#include <iostream>
#include <string>
#include <vector>
#include "MakeCanvas_SP8.h"
#include "Analysis_SP8.h"
using namespace std;
#define RF 1.966

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
    cout << Form("run%d", run) << endl;
    cout << "Event: " << nEntries << endl;
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

void Analysis:: Select(){
    BCheck=1;
    return;
}

void Analysis:: MakeCanvas(){
    if(BCheck){
        CLtdc1= new TCanvas("CLtdc1", "CLtdc1", 2000, 2000);
        CLtdc2= new TCanvas("CLtdc2", "CLtdc2", 2000, 2000);
        CTtdc1= new TCanvas("CTtdc1", "CTtdc1", 2000, 2000);
        CTtdc2= new TCanvas("CTtdc2", "CTtdc2", 2000, 2000);
        CWidth1= new TCanvas("CWidth1", "CWidth1", 2000, 2000);
        CWidth2= new TCanvas("CWidth2", "CWidth2", 2000, 2000);
        CLtdc1-> Divide(4,4);
        CLtdc2-> Divide(4,4);
        CTtdc1-> Divide(4,4);
        CTtdc2-> Divide(4,4);
        CWidth1-> Divide(4,4);
        CWidth2-> Divide(4,4);
        for(Int_t ch=0; ch<32; ch++){
            HLtdc1[ch]= new TH1D(Form("run%d_HLtdc[%d]", Run, ch), Form("run%d_HLtdc[%d]", Run, ch), 3000, 0, 600);
            HLtdc2[ch]= new TH1D(Form("run%d_HLtdc[%d]", Run, ch), Form("run%d_HLtdc[%d]", Run, ch), 3000, 0, 600);
            HLtdc3[ch]= new TH1D(Form("run%d_HLtdc[%d]", Run, ch), Form("run%d_HLtdc[%d]", Run, ch), 3000, 0, 600);
            HTtdc1[ch]= new TH1D(Form("run%d_HTtdc[%d]", Run, ch), Form("run%d_HTtdc[%d]", Run, ch), 3000, 0, 600);
            HTtdc2[ch]= new TH1D(Form("run%d_HTtdc[%d]", Run, ch), Form("run%d_HTtdc[%d]", Run, ch), 3000, 0, 600);
            HTtdc3[ch]= new TH1D(Form("run%d_HTtdc[%d]", Run, ch), Form("run%d_HTtdc[%d]", Run, ch), 3000, 0, 600);
            HWidth1[ch]= new TH1D(Form("run%d_HWidth[%d]", Run, ch), Form("run%d_HWidth[%d]", Run, ch), 3000, 0, 600);
            HWidth2[ch]= new TH1D(Form("run%d_HWidth[%d]", Run, ch), Form("run%d_HWidth[%d]", Run, ch), 3000, 0, 600);
            HWidth3[ch]= new TH1D(Form("run%d_HWidth[%d]", Run, ch), Form("run%d_HWidth[%d]", Run, ch), 3000, 0, 600);
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
    return;
}

void Analysis:: RunEventLoop(){
    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
        if(BCheck){
            tree-> GetEntry(iEntry);
            if(iEntry<0) break;
            indicator(iEntry, nEntries);
            if(BCheck) Check();
        }
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
    return;
}

void Analysis:: Save(){
    cout << "\r" << Form("Save Histgram and Canvas into ./../Save/run%d_plot.root", Run) << flush;
    TFile *fout= new TFile(Form("./../Save/run%d_plot.root", Run), "recreate");
    TTree *cptree= tree-> CloneTree();
    cptree-> Write();
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
    return;
}

void Analysis_SP8(Int_t run){
    Analysis* a= new Analysis(run);
    a-> Select();
    a-> MakeCanvas();
    a-> RunEventLoop();
    a-> DrawPlot();
    a-> Save();
    return;
}