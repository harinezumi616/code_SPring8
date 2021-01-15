#include <iostream>
#include <string>
#include <vector>
#include "Select_SP8.h"
#include "MakeCanvas_SP8.h"
#include "Analysis_SP8.h"
using namespace std;
#define RF 1.966
#define REDi "\e[0;31m"
#define REDf "\033[m"

Analysis:: Analysis(Int_t run){
    file= new TFile(Form("./../../Data/run%06d_0.root", run), "read");
    if(!file || !file-> IsOpen()){
        cout << Form("can not open run%06d_0.root", run) << endl;
        return;
    }
    tree= (TChain*)file-> Get("tree");
    Init(tree);
    Run= run;
    gStyle-> SetOptFit(11111111);
    gStyle-> SetOptStat(11111111);
    nEntries= tree-> GetEntriesFast();
    cout << Form("Data File:run%d", run) << endl;
    cout << "Event    : " << nEntries << endl;
}

Analysis:: ~Analysis(){
    if (!tree) return;
    file-> Close();
    delete tree-> GetCurrentFile();
}

void Analysis:: Init(TChain *tree){
    tree-> SetBranchAddress("amp", &amp, &b_amp);
    tree-> SetBranchAddress("dt", &dt, &b_dt);
    tree-> SetBranchAddress("width", &width, &b_width);
    tree-> SetBranchAddress("l1_tdc", &l1_tdc, &b_l1_tdc);
    tree-> SetBranchAddress("l1_tdc1", &l1_tdc1, &b_l1_tdc1);
    tree-> SetBranchAddress("ltdc", &ltdc, &b_ltdc);
    tree-> SetBranchAddress("ttdc", &ttdc, &b_ttdc);
    tree-> GetEntry(0);
    tree-> SetBranchStatus("*", 0);
    tree-> SetBranchStatus("amp", 1);
    tree-> SetBranchStatus("ltdc", 1);
    tree-> SetBranchStatus("ttdc", 1);
    return;
}

void Analysis:: MakeCanvas(){
    if(BCheck){
        CLtdc1= new TCanvas(Form("run%d_CLtdc1", Run), Form("run%d_CLtdc1", Run), 2000, 2000);
        CLtdc2= new TCanvas(Form("run%d_CLtdc2", Run), Form("run%d_CLtdc2", Run), 2000, 2000);
        CTtdc1= new TCanvas(Form("run%d_CTtdc1", Run), Form("run%d_CTtdc1", Run), 2000, 2000);
        CTtdc2= new TCanvas(Form("run%d_CTtdc2", Run), Form("run%d_CTtdc2", Run), 2000, 2000);
        CWidth1= new TCanvas(Form("run%d_CWidth1", Run), Form("run%d_Width1", Run), 2000, 2000);
        CWidth2= new TCanvas(Form("run%d_CWidth2", Run), Form("run%d_Width2", Run), 2000, 2000);
        CLtdc1-> Divide(4,4);
        CLtdc2-> Divide(4,4);
        CTtdc1-> Divide(4,4);
        CTtdc2-> Divide(4,4);
        CWidth1-> Divide(4,4);
        CWidth2-> Divide(4,4);
        for(Int_t ch=0; ch<32; ch++){
            HLtdc1[ch]= new TH1D(Form("run%d_HLtdc1[%d]", Run, ch), Form("run%d_HLtdc1[%d]", Run, ch), 3000, 0, 600);
            HLtdc2[ch]= new TH1D(Form("run%d_HLtdc2[%d]", Run, ch), Form("run%d_HLtdc2[%d]", Run, ch), 3000, 0, 600);
            HLtdc3[ch]= new TH1D(Form("run%d_HLtdc3[%d]", Run, ch), Form("run%d_HLtdc3[%d]", Run, ch), 3000, 0, 600);
            HTtdc1[ch]= new TH1D(Form("run%d_HTtdc1[%d]", Run, ch), Form("run%d_HTtdc1[%d]", Run, ch), 3000, 0, 600);
            HTtdc2[ch]= new TH1D(Form("run%d_HTtdc2[%d]", Run, ch), Form("run%d_HTtdc2[%d]", Run, ch), 3000, 0, 600);
            HTtdc3[ch]= new TH1D(Form("run%d_HTtdc3[%d]", Run, ch), Form("run%d_HTtdc3[%d]", Run, ch), 3000, 0, 600);
            HWidth1[ch]= new TH1D(Form("run%d_HWidth1[%d]", Run, ch), Form("run%d_HWidth1[%d]", Run, ch), 150, 0, 30);
            HWidth2[ch]= new TH1D(Form("run%d_HWidth2[%d]", Run, ch), Form("run%d_HWidth2[%d]", Run, ch), 150, 0, 30);
            HWidth3[ch]= new TH1D(Form("run%d_HWidth3[%d]", Run, ch), Form("run%d_HWidth3[%d]", Run, ch), 150, 0, 30);
            HLtdc1[ch]-> SetLineColor(kRed);
            HLtdc2[ch]-> SetLineColor(kBlue);
            HLtdc3[ch]-> SetLineColor(kBlack);
            HTtdc1[ch]-> SetLineColor(kRed);
            HTtdc2[ch]-> SetLineColor(kBlue);
            HTtdc3[ch]-> SetLineColor(kBlack);
            HWidth1[ch]-> SetLineColor(kRed);
            HWidth2[ch]-> SetLineColor(kBlue);
            HWidth3[ch]-> SetLineColor(kBlack);
        }
    }
    if(BGetTimeReso){
        CRFLtdc= new TCanvas(Form("run%d_CRFLtdc", Run), Form("run%d_CRFLtdc", Run), 2000, 2000);
        HRFLtdc= new TH1D(Form("run%d_HRFLtdc", Run), Form("run%d_HRFLtdc", Run), 1000, 0, 1000);
    }
    return;
}

void Analysis:: RunEventLoop(){
    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
        tree-> GetEntry(iEntry);
        if(iEntry<0) break;
        indicator(iEntry, nEntries);
        if(BSetData) SetData();
        if(BCheck && BSetData) Check(BSetData);
        if(BCheck && !BSetData) Check();
        if(BGetTimeReso) GetTimeReso();
    }
    return;
}

void Analysis:: DrawPlot(){
    if(BCheck){
        for(Int_t ch=0; ch<32; ch++){
            if(ch<16){
                CLtdc1-> cd(ch+1);
                HLtdc1[ch]-> Draw();
                HLtdc2[ch]-> Draw("same");
                HLtdc3[ch]-> Draw("same");
                CTtdc1-> cd(ch+1);
                HTtdc1[ch]-> Draw();
                HTtdc2[ch]-> Draw("same");
                HTtdc3[ch]-> Draw("same");
                CWidth1-> cd(ch+1);
                HWidth1[ch]-> Draw();
                HWidth2[ch]-> Draw("same");
                HWidth3[ch]-> Draw("same");
            }
            else{
                CLtdc2-> cd(ch-15);
                HLtdc1[ch]-> Draw();
                HLtdc2[ch]-> Draw("same");
                HLtdc3[ch]-> Draw("same");
                CTtdc2-> cd(ch-15);
                HTtdc1[ch]-> Draw();
                HTtdc2[ch]-> Draw("same");
                HTtdc3[ch]-> Draw("same");
                CWidth2-> cd(ch-15);
                HWidth1[ch]-> Draw();
                HWidth2[ch]-> Draw("same");
                HWidth3[ch]-> Draw("same");
            }
        }
    }
    if(BGetTimeReso){

    }
    return;
}

void Analysis:: Save(){
    cout << "\r" << Form("Save Histgram and Canvas into ./../Save/run%d_plot.root", Run) << flush << endl;
    TFile *fout= new TFile(Form("./../Save/run%d_plot.root", Run), "recreate");
    // TTree *cptree= tree-> CloneTree();
    // cptree-> Write();
    if(BCheck){
        CLtdc1-> Write();
        CLtdc2-> Write();
        CTtdc1-> Write();
        CTtdc2-> Write();
        CWidth1-> Write();
        CWidth2-> Write();
        for(Int_t ch=0; ch<32; ch++){
        HLtdc1[ch]-> Write();
        HLtdc2[ch]-> Write();
        HLtdc3[ch]-> Write();
        HTtdc1[ch]-> Write();
        HTtdc2[ch]-> Write();
        HTtdc3[ch]-> Write();
        HWidth1[ch]-> Write();
        HWidth2[ch]-> Write();
        HWidth3[ch]-> Write();
        }
    }
    if(BGetTimeReso){
        CRFLtdc-> Write();
        HRFLtdc-> Write();
    }
    return;
}

void Analysis:: indicator(Int_t iEntry, Int_t nEntries){
    Int_t percent= 100*(iEntry+1)/nEntries;
    if(percent==percent_tmp) return;
    else if(percent<10)   cout << "\r" << "[__________]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<20)   cout << "\r" << "[#_________]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<30)   cout << "\r" << "[##________]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<40)   cout << "\r" << "[###_______]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<50)   cout << "\r" << "[####______]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<60)   cout << "\r" << "[#####_____]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<70)   cout << "\r" << "[######____]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<80)   cout << "\r" << "[#######___]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<90)   cout << "\r" << "[########__]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent<100)  cout << "\r" << "[#########_]  "  << percent << "%" << string(5, ' ') << flush;
    else if(percent==100) cout << "\r" << "[##########]  "  << percent << "%" << string(10, ' ') << endl;
    percent_tmp = percent;
    return;
}

void Analysis:: SetData(){
    ReconfigLtdc.clear();
    ReconfigTtdc.clear();
    ReconfigWidth.clear();
    for(Int_t ch=0; ch<32; ch++){
        Int_t i=0;
        Int_t j=0;
        ReconfigLtdc.emplace_back();
        ReconfigTtdc.emplace_back();
        ReconfigWidth.emplace_back();
        Int_t nltdc= ltdc->at(ch).size();
        Int_t nttdc= ttdc->at(ch).size();
        while(i<nltdc-1 && j<nttdc){
            if(ltdc->at(ch).at(i+1)>ttdc->at(ch).at(j)) i++;
            else if(ttdc->at(ch).at(j)>ltdc->at(ch).at(i)) j++;
            else if(ltdc->at(ch).at(i)>ttdc->at(ch).at(j) && ttdc->at(ch).at(j)>=ltdc->at(ch).at(i+1)){
                ReconfigLtdc.at(ch).emplace_back(ltdc->at(ch).at(i));
                ReconfigTtdc.at(ch).emplace_back(ttdc->at(ch).at(j));
                ReconfigWidth.at(ch).emplace_back(ltdc->at(ch).at(i) - ttdc->at(ch).at(j));
                Int_t nReconfigLtdc= ReconfigLtdc.at(ch).size();
                Int_t nReconfigTtdc= ReconfigTtdc.at(ch).size();
                // cout << Form("ReconfigLtdc.at(%2d).at(%2d)= ", ch, nReconfigLtdc-1) << ReconfigLtdc.at(ch).at(nReconfigLtdc-1) << endl;
                // cout << Form("ReconfigTtdc.at(%2d).at(%2d)= ", ch, nReconfigTtdc-1) << ReconfigTtdc.at(ch).at(nReconfigTtdc-1) << endl;
                i++;
                j++;
            }
            else{
                // cout << ch << ":" << ltdc->at(ch).at(i+1) << ":" << ttdc->at(ch).at(j) << ":" << ltdc->at(ch).at(i) <<endl;
                i++;
            }
        }
    }
    return;
}

Bool_t Analysis:: HitStrip(Int_t Strip=0){
    if(Strip==0){
        if(ltdc->at(1).size()!=0 && ltdc->at(4).size()!=0) return true;
        else return false;
    }
    else if(Strip==1){
        if(ltdc->at(0).size()!=0 && ltdc->at(3).size()!=0) return true;
        else return false;
    }
    else if(Strip==-1){
        if(ltdc->at(2).size()!=0 && ltdc->at(5).size()!=0) return true;
        else return false;
    }
    else{
        cout << REDi "error: " REDf << "call of not exisiting the strip" << endl;
        Analysis:: ~Analysis();
        exit(1);
        return false;
    }
}

Double_t Analysis:: GetLtdc(Int_t ch, Int_t Nth=0){
    if(BSetData){
        return ReconfigLtdc.at(ch).at(Nth);
    }
    else{
        if(!BSetData){
            if(ltdc->at(ch).at(0)>ttdc->at(ch).at(0)) return ltdc->at(ch).at(0);
            else ltdc->at(ch).at(1);
        }
        else return ltdc->at(ch).at(Nth);
    }
};
Double_t Analysis:: GetTtdc(Int_t ch, Int_t Nth=0);
Double_t Analysis:: GetWidth(Int_t ch, Int_t Nth=0);

void Analysis:: Check(){
    // cout << "Check()" << endl;
    for(Int_t ch=0; ch<32; ch++){
        for(Int_t i=0; i<ltdc->at(ch).size(); i++){
            if(i==0) HLtdc1[ch]-> Fill(ltdc->at(ch).at(i));
            else if(i==1) HLtdc2[ch]-> Fill(ltdc->at(ch).at(i));
            else HLtdc3[ch]-> Fill(ltdc->at(ch).at(i));
        }
        for(Int_t i=0; i<ttdc->at(ch).size(); i++){
            if(i==0) HTtdc1[ch]-> Fill(ttdc->at(ch).at(i));
            else if(i==1) HTtdc2[ch]-> Fill(ttdc->at(ch).at(i));
            else HTtdc3[ch]-> Fill(ttdc->at(ch).at(i));
        }
        if(ltdc->at(ch).size()<ttdc->at(ch).size()){
            for(Int_t i=0; i<ltdc->at(ch).size(); i++){
                if(i==0) HWidth1[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
                else if(i==1) HWidth2[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
                else HWidth3[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
            }
        }
        if(ttdc->at(ch).size()<ltdc->at(ch).size()){
            for(Int_t i=0; i<ttdc->at(ch).size(); i++){
                if(i==0) HWidth1[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
                else if(i==1) HWidth2[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
                else HWidth3[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
            }
        }
    }
    return;
}

void Analysis:: Check(Bool_t BSetData){
    // cout << "Check(BSetData)" << endl;
    for(Int_t ch=0; ch<32; ch++){
        for(Int_t i=0; i<ReconfigLtdc.at(ch).size(); i++){
            if(i==0) HLtdc1[ch]-> Fill(ReconfigLtdc.at(ch).at(i));
            else if(i==1) HLtdc2[ch]-> Fill(ReconfigLtdc.at(ch).at(i));
            else HLtdc3[ch]-> Fill(ReconfigLtdc.at(ch).at(i));
        }
        for(Int_t i=0; i<ReconfigTtdc.at(ch).size(); i++){
            if(i==0) HTtdc1[ch]-> Fill(ReconfigTtdc.at(ch).at(i));
            else if(i==1) HTtdc2[ch]-> Fill(ReconfigTtdc.at(ch).at(i));
            else HTtdc3[ch]-> Fill(ReconfigTtdc.at(ch).at(i));
        }
        for(Int_t i=0; i<ReconfigWidth.at(ch).size(); i++){
            if(i==0) HWidth1[ch]-> Fill(ReconfigWidth.at(ch).at(i));
            else if(i==1) HWidth2[ch]-> Fill(ReconfigWidth.at(ch).at(i));
            else HWidth3[ch]-> Fill(ReconfigWidth.at(ch).at(i));
        }
    }
    return;
}

void Analysis:: GetTimeReso(){
    Bool_t C1= HitStrip();
    Double_t mean;
    Double_t RFmean;
    if(C1){
    }
}

void Analysis_SP8(Int_t run){
    Analysis* a= new Analysis(run);
    a-> MakeCanvas();
    a-> RunEventLoop();
    a-> DrawPlot();
    a-> Save();
    return;
}

void Analysis_SP8(){
    cout << REDi "error: " REDf << "enter the run number like follow example" << endl;
    cout << "\"" << REDi "user$ root Analysis_SP8.cpp\\(run number\\)" REDf << "\"" << endl;
    cout << "or" << endl;
    cout << "\"" << REDi "user$ root" REDf << "\"" << endl;
    cout << "\"" << REDi "root [0] .x Analysis_SP8.cpp(run number)" REDf << "\"" << endl;
    exit(1);
    return;
}