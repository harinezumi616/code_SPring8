#include <iostream>
#include <string>
#include <vector>
#include "Select_SP8.h"
#include "MakeCanvas_SP8.h"
#include "Analysis_SP8.h"
using namespace std;
#define RF 1.966
#define UL "\033[04m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define END33 "\033[m"

Analysis:: Analysis(Int_t run){
    file= new TFile(Form("./../../Data/run%06d_0.root", run), "read");
    if(!file || !file-> IsOpen()){
        cout <<  RED "error: " END33 << Form("can not open run%06d_0.root", run) << endl;
        exit(1);
        return;
    }
    tree= (TChain*)file-> Get("tree");
    Init(tree);
    Run= run;
    gStyle-> SetOptFit(111111111);
    gStyle-> SetOptStat(111111111);
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

void Analysis:: MakeCanvas1(){
    if(BCheck){
        CLtdc1= new TCanvas(Form("run%d_CLtdc1", Run), Form("run%d_CLtdc1", Run), 2000, 2000);
        CLtdc2= new TCanvas(Form("run%d_CLtdc2", Run), Form("run%d_CLtdc2", Run), 2000, 2000);
        CTtdc1= new TCanvas(Form("run%d_CTtdc1", Run), Form("run%d_CTtdc1", Run), 2000, 2000);
        CTtdc2= new TCanvas(Form("run%d_CTtdc2", Run), Form("run%d_CTtdc2", Run), 2000, 2000);
        CWidth1= new TCanvas(Form("run%d_CWidth1", Run), Form("run%d_CWidth1", Run), 2000, 2000);
        CWidth2= new TCanvas(Form("run%d_CWidth2", Run), Form("run%d_CWidth2", Run), 2000, 2000);
        CAmp1= new TCanvas(Form("run%d_CAmp1", Run), Form("run%d_CAmp1", Run), 2000, 2000);
        CLtdc1-> Divide(4,4);
        CLtdc2-> Divide(4,4);
        CTtdc1-> Divide(4,4);
        CTtdc2-> Divide(4,4);
        CWidth1-> Divide(4,4);
        CWidth2-> Divide(4,4);
        CAmp1-> Divide(4,4);
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
        for(Int_t ch=0; ch<16; ch++){
            HAmp1[ch]= new TH1D(Form("run%d_HAmp1[%d]", Run, ch), Form("run%d_HAmp1[%d]", Run, ch), 500, 0, 500);
            HAmp2[ch]= new TH1D(Form("run%d_HAmp2[%d]", Run, ch), Form("run%d_HAmp2[%d]", Run, ch), 500, 0, 500);
            HAmp3[ch]= new TH1D(Form("run%d_HAmp3[%d]", Run, ch), Form("run%d_HAmp3[%d]", Run, ch), 500, 0, 500);
            HAmp1[ch]-> SetLineColor(kRed);
            HAmp2[ch]-> SetLineColor(kBlue);
            HAmp3[ch]-> SetLineColor(kBlack);
        }
    }
    if(BGetTimeReso){
        CRF= new TCanvas(Form("run%d_CRF", Run), Form("run%d_CRF", Run), 2000, 2000);
        CRFLtdc= new TCanvas(Form("run%d_CRFLtdc", Run), Form("run%d_CRFLtdc", Run), 2000, 2000);
        CRFLtdc-> Divide(1,3);
        HRF= new TH1D(Form("run%d_HRF", Run), Form("run%d_HRF", Run), 2000, 580, 780);
        HRFLtdcRight= new TH1D(Form("run%d_HRFLtdcRight", Run), Form("run%d_HRFLtdcRight", Run), 6000, 380, 580);
        HRFLtdcLeft= new TH1D(Form("run%d_HRFLtdcLeft", Run), Form("run%d_HRFLtdcLeft", Run), 6000, 380, 580);
        HRFLtdcMean= new TH1D(Form("run%d_HRFLtdcMean", Run), Form("run%d_HRFLtdcMean", Run), 6000, 380, 580);
        FRight= new TF1("FRight", "gaus", 0, 600);
        FLeft= new TF1("FLeft", "gaus", 0, 600);
        FMean= new TF1("FMean", "gaus", 0, 600);
    }
    return;
}

void Analysis:: MakeCanvas2(){
    for(Int_t i=0; i<3; i++){
        CDivision[i]= new TCanvas(Form("run%d_CDivision[%d]", Run, i), Form("run%d_CDivision[%d]", Run, i), 2000, 2000);
        CDivision[i]-> Divide(10,8);
    }
    CMerge= new TCanvas(Form("run%d_CMerge", Run), Form("run%d_CMerge", Run), 2000, 2000);
    CMerge2D= new TCanvas(Form("run%d_CMerge2D", Run), Form("run%d_CMerge2D", Run), 2000, 2000);
    CMerge-> Divide(3,1);
    CMerge2D-> Divide(2,2);
    for(Int_t i=0; i<80; i++){
        HDivisionRight[i]= new TH1D(Form("run%d_HDivivisonRight[%d]", Run, i), Form("run%d_HDivivisonRight[%d]", Run, i), 30*RF, iGaussRight+RF*(2*i-1)/2., iGaussRight+RF*(2*i+1)/2.);
        HDivisionLeft[i]= new TH1D(Form("run%d_HDivivisonLeft[%d]", Run, i), Form("run%d_HDivivisonLeft[%d]", Run, i), 30*RF, iGaussLeft+RF*(2*i-1)/2., iGaussLeft+RF*(2*i+1)/2.);
        HDivisionMean[i]= new TH1D(Form("run%d_HDivivisonMean[%d]", Run, i), Form("run%d_HDivivisonMean[%d]", Run, i), 30*RF, iGaussMean+RF*(2*i-1)/2., iGaussMean+RF*(2*i+1)/2.);
    }
    HMergeRight= new TH1D(Form("run%d_HMergeRight", Run), Form("run%d_HMergeRight", Run), 100*RF, -RF/2., RF/2.);
    HMergeLeft= new TH1D(Form("run%d_HMergeLeft", Run), Form("run%d_HMergeLeft", Run), 100*RF, -RF/2., RF/2.);
    HMergeMean= new TH1D(Form("run%d_HMergeMean", Run), Form("run%d_HMergeMean", Run), 100*RF, -RF/2., RF/2.);
    HMergeRight2D= new TH2D(Form("run%d_HMergeRight2D", Run), Form("run%d_HMergeRight2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    HMergeLeft2D= new TH2D(Form("run%d_HMergeLeft2D", Run), Form("run%d_HMergeLeft2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    HMergeMeanR2D= new TH2D(Form("run%d_HMergeMeanR2D", Run), Form("run%d_HMergeMeanR2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    HMergeMeanL2D= new TH2D(Form("run%d_HMergeMeanL2D", Run), Form("run%d_HMergeMeanL2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    FSlewingMR= new TF1("FSlewingMR", "[0]+[1]*x+[2]*pow(x,2)+[3]*pow(x,3)+[4]*pow(x,4)+[5]*pow(x,5)+[6]*pow(x,6)+[7]*pow(x,7)+[8]*pow(x,8)+[9]*pow(x,9)", 0, 15);
    FSlewingML= new TF1("FSlewingML", "[0]+[1]*x+[2]*pow(x,2)+[3]*pow(x,3)+[4]*pow(x,4)+[5]*pow(x,5)+[6]*pow(x,6)+[7]*pow(x,7)+[8]*pow(x,8)+[9]*pow(x,9)", 0, 15);
    FSlewingMMR= new TF1("FSlewingMMR", "[0]+[1]*x+[2]*pow(x,2)+[3]*pow(x,3)+[4]*pow(x,4)+[5]*pow(x,5)+[6]*pow(x,6)+[7]*pow(x,7)+[8]*pow(x,8)+[9]*pow(x,9)", 0, 15);
    FSlewingMML= new TF1("FSlewingMML", "[0]+[1]*x+[2]*pow(x,2)+[3]*pow(x,3)+[4]*pow(x,4)+[5]*pow(x,5)+[6]*pow(x,6)+[7]*pow(x,7)+[8]*pow(x,8)+[9]*pow(x,9)", 0, 15);
    // FSlewingMR= new TF1("FSlewingMR", "[0]+[1]/(x+[2])+[3]/sqrt(x+[4])", 0, 15);
    // FSlewingML= new TF1("FSlewingML", "[0]+[1]/(x+[2])+[3]/sqrt(x+[4])", 0, 15);
    // FSlewingMMR= new TF1("FSlewingMMR", "[0]+[1]/(x+[2])+[3]/sqrt(x+[4])", 0, 15);
    // FSlewingMML= new TF1("FSlewingMML", "[0]+[1]/(x+[2])+[3]/sqrt(x+[4])", 0, 15);
}

void Analysis:: MakeCanvas3(){
    CSlewing= new TCanvas(Form("run%d_CSlewing", Run), Form("run%d_CSlewing", Run), 2000, 2000);
    CSlewing2D= new TCanvas(Form("run%d_CSlewing2D", Run), Form("run%d_CSlewing2D", Run), 2000, 2000);
    CSlewing-> Divide(2,2);
    CSlewing2D-> Divide(2,2);
    HSlewingRight= new TH1D(Form("run%d_HSlewingRight", Run), Form("run%d_HSlewingRight", Run), 100*RF, -RF/2., RF/2.);
    HSlewingLeft= new TH1D(Form("run%d_HSlewingLeft", Run), Form("run%d_HSlewingLeft", Run), 100*RF, -RF/2., RF/2.);
    HSlewingMeanR= new TH1D(Form("run%d_HSlewingMeanR", Run), Form("run%d_HSlewingMeanR", Run), 100*RF, -RF/2., RF/2.);
    HSlewingMeanL= new TH1D(Form("run%d_HSlewingMeanL", Run), Form("run%d_HSlewingMeanL", Run), 100*RF, -RF/2., RF/2.);
    HSlewingRight2D= new TH2D(Form("run%d_HSlewingRight2D", Run), Form("run%d_HSlewingRight2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    HSlewingLeft2D= new TH2D(Form("run%d_HSlewingLeft2D", Run), Form("run%d_HSlewingLeft2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    HSlewingMeanR2D= new TH2D(Form("run%d_HSlewingMeanR2D", Run), Form("run%d_HSlewingMeanR2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    HSlewingMeanL2D= new TH2D(Form("run%d_HSlewingMeanL2D", Run), Form("run%d_HSlewingMeanL2D", Run), 150, 0, 15, 100*RF, -RF/2., RF/2.);
    FRightSlewing= new TF1("FRightSlewing", "gaus", -RF/2., RF/2.);
    FLeftSlewing= new TF1("FLeftSlewing", "gaus", -RF/2., RF/2.);
    FMeanRSlewing= new TF1("FMeanRSlewing", "gaus", -RF/2., RF/2.);
    FMeanLSlewing= new TF1("FMeanLSlewing", "gaus", -RF/2., RF/2.);
}

void Analysis:: RunEventLoop(){
    MakeCanvas1();
    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
    // for(Int_t iEntry=0; iEntry<50; iEntry++){
        tree-> GetEntry(iEntry);
        indicator(iEntry, nEntries);
        if(BSetData) SetData();
        if(BCheckData && !BSetData) CheckData(iEntry);
        if(BCheckSetData && BSetData) CheckSetData(iEntry);
        if(BCheck && !BSetData) Check();
        if(BCheck && BSetData) Check(BSetData);
        if(BGetTimeReso) GetRFDist();
    }
    if(BGetTimeReso) GetPeak();
    if(BGetTimeReso) MakeCanvas2();
    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
        tree-> GetEntry(iEntry);
        indicator(iEntry, nEntries);
        if(BGetTimeReso) GetTimeReso();
    }
    if(BGetTimeReso) GetFitFunction();
    if(BGetTimeReso) MakeCanvas3();
    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
        tree-> GetEntry(iEntry);
        indicator(iEntry, nEntries);
        if(BGetTimeReso) GetSlewing();
    }
    DrawPlot();
    return;
}

void Analysis:: DrawPlot(){
    if(BCheck){
        for(Int_t ch=0; ch<32; ch++){
            if(ch<16){
                CLtdc1-> cd(ch+1);
                HLtdc1[ch]-> Draw();
                HLtdc3[ch]-> Draw("sames");
                HLtdc2[ch]-> Draw("sames");
                HLtdc1[ch]-> Draw("sames");
                CTtdc1-> cd(ch+1);
                HTtdc1[ch]-> Draw();
                HTtdc3[ch]-> Draw("sames");
                HTtdc2[ch]-> Draw("sames");
                HTtdc1[ch]-> Draw("sames");
                CWidth1-> cd(ch+1);
                HWidth1[ch]-> Draw();
                HWidth3[ch]-> Draw("sames");
                HWidth2[ch]-> Draw("sames");
                HWidth1[ch]-> Draw("sames");
                CAmp1-> cd(ch+1);
                HAmp1[ch]-> Draw();
                HAmp3[ch]-> Draw("sames");
                HAmp2[ch]-> Draw("sames");
                HAmp1[ch]-> Draw("sames");
            }
            else{
                CLtdc2-> cd(ch-15);
                HLtdc1[ch]-> Draw();
                HLtdc3[ch]-> Draw("sames");
                HLtdc2[ch]-> Draw("sames");
                HLtdc1[ch]-> Draw("sames");
                CTtdc2-> cd(ch-15);
                HTtdc1[ch]-> Draw();
                HTtdc3[ch]-> Draw("sames");
                HTtdc2[ch]-> Draw("sames");
                HTtdc1[ch]-> Draw("sames");
                CWidth2-> cd(ch-15);
                HWidth1[ch]-> Draw();
                HWidth3[ch]-> Draw("sames");
                HWidth2[ch]-> Draw("sames");
                HWidth1[ch]-> Draw("sames");
            }
        }
    }
    if(BGetTimeReso){
        CRF-> cd();
        HRF-> Draw();
        CRFLtdc-> cd(1);
        HRFLtdcRight-> Draw();
        CRFLtdc-> cd(2);
        HRFLtdcLeft-> Draw();
        CRFLtdc-> cd(3);
        HRFLtdcMean-> Draw();
        for(Int_t i=0; i<80; i++){
            CDivision[0]-> cd(i+1);
            HDivisionRight[i]-> Draw();
            CDivision[1]-> cd(i+1);
            HDivisionLeft[i]-> Draw();
            CDivision[2]-> cd(i+1);
            HDivisionMean[i]-> Draw();
        }
        CMerge-> cd(1);
        HMergeRight-> Fit("gaus", "Q", "", -0.2, 0.2);
        HMergeRight-> Draw();
        CMerge-> cd(2);
        HMergeLeft-> Fit("gaus", "Q", "", -0.2, 0.2);
        HMergeLeft-> Draw();
        CMerge-> cd(3);
        HMergeMean-> Fit("gaus", "Q", "", -0.2, 0.2);
        HMergeMean-> Draw();
        CMerge2D-> cd(1);
        HMergeRight2D-> Draw("colz");
        PMergeRight2D-> Draw("same");
        CMerge2D-> cd(2);
        HMergeLeft2D-> Draw("colz");
        PMergeLeft2D-> Draw("same");
        CMerge2D-> cd(3);
        HMergeMeanR2D-> Draw("colz");
        PMergeMeanR2D-> Draw("same");
        CMerge2D-> cd(4);
        HMergeMeanL2D-> Draw("colz");
        PMergeMeanL2D-> Draw("same");
        CSlewing-> cd(1);
        HSlewingRight-> Fit("FRightSlewing", "Q", "", -0.2, 0.2);
        HSlewingRight-> Draw();
        CSlewing-> cd(2);
        HSlewingLeft-> Fit("FLeftSlewing", "Q", "", -0.2, 0.2);
        HSlewingLeft-> Draw();
        CSlewing-> cd(3);
        HSlewingMeanR-> Fit("FMeanRSlewing", "Q", "", -0.2, 0.2);
        HSlewingMeanR-> Draw();
        CSlewing-> cd(4);
        HSlewingMeanL-> Fit("FMeanLSlewing", "Q", "", -0.2, 0.2);
        HSlewingMeanL-> Draw();
        CSlewing2D-> cd(1);
        HSlewingRight2D-> Draw("colz");
        CSlewing2D-> cd(2);
        HSlewingLeft2D-> Draw("colz");
        CSlewing2D-> cd(3);
        HSlewingMeanR2D-> Draw("colz");
        CSlewing2D-> cd(4);
        HSlewingMeanL2D-> Draw("colz");
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
        CAmp1-> Write();
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
        for(Int_t ch=0; ch<16; ch++){
            HAmp1[ch]-> Write();
            HAmp2[ch]-> Write();
            HAmp3[ch]-> Write();
        }
    }
    if(BGetTimeReso){
        CRF-> Write();
        CRFLtdc-> Write();
        for(Int_t i=0; i<3; i++){
            CDivision[i]-> Write();
        }
        CMerge-> Write();
        CMerge2D-> Write();
        CSlewing-> Write();
        CSlewing2D-> Write();
        HRF-> Write();
        HRFLtdcRight-> Write();
        HRFLtdcLeft-> Write();
        HRFLtdcMean-> Write();
        for(Int_t i=0; i<80; i++){
            HDivisionRight[i]-> Write();
            HDivisionLeft[i]-> Write();
            HDivisionMean[i]-> Write();
        }
        HMergeRight-> Write();
        HMergeLeft-> Write();
        HMergeMean-> Write();
        HMergeRight2D-> Write();
        HMergeLeft2D-> Write();
        HMergeMeanR2D-> Write();
        HMergeMeanL2D-> Write();
        HSlewingRight-> Write();
        HSlewingLeft-> Write();
        HSlewingMeanR-> Write();
        HSlewingMeanL-> Write();
        HSlewingRight2D-> Write();
        HSlewingLeft2D-> Write();
        HSlewingMeanR2D-> Write();
        HSlewingMeanL2D-> Write();
    }
    return;
}

Bool_t Analysis:: HitStrip(Int_t Strip=0){
    Bool_t HitRight=0;
    Bool_t HitLeft=0;
    if(BSetData){
        if(Strip==0){
            if(ReconfigLtdc.at(1).size()!=0 && ReconfigTtdc.at(1).size()!=0){
                if(ReconfigLtdc.at(1).at(0)>ReconfigTtdc.at(1).at(0)) HitRight=1;
                else HitRight=0;
            }
            if(ReconfigLtdc.at(4).size()!=0 && ReconfigTtdc.at(4).size()!=0){
                if(ReconfigLtdc.at(4).at(0)>ReconfigTtdc.at(4).at(0)) HitLeft=1;
                else HitLeft=0;
            }
            if(HitRight && HitLeft) return true;
            else return false;
        }
        else if(Strip==1){
            if(ReconfigLtdc.at(0).size()!=0 && ReconfigTtdc.at(0).size()!=0){
                if(ReconfigLtdc.at(0).at(0)>ReconfigTtdc.at(0).at(0)) HitRight=1;
                else HitRight=0;
            }
            if(ReconfigLtdc.at(3).size()!=0 && ReconfigTtdc.at(3).size()!=0){
                if(ReconfigLtdc.at(3).at(0)>ReconfigTtdc.at(3).at(0)) HitLeft=1;
                else HitLeft=0;
            }
            if(HitRight && HitLeft) return true;
            else return false;
        }
        else if(Strip==-1){
            if(ReconfigLtdc.at(2).size()!=0 && ReconfigTtdc.at(2).size()!=0){
                if(ReconfigLtdc.at(2).at(0)>ReconfigTtdc.at(2).at(0)) HitRight=1;
                else HitRight=0;
            }
            if(ReconfigLtdc.at(5).size()!=0 && ReconfigTtdc.at(5).size()!=0){
                if(ReconfigLtdc.at(5).at(0)>ReconfigTtdc.at(5).at(0)) HitLeft=1;
                else HitLeft=0;
            }
            if(HitRight && HitLeft) return true;
            else return false;
        }
        else{
            cout << RED "error: " END33 << "call of not exisiting the strip" << endl;
            Analysis:: ~Analysis();
            exit(1);
            return false;
        }
    }
    else{
        if(Strip==0){
            if(ltdc->at(1).size()!=0 && ttdc->at(1).size()!=0){
                if(ltdc->at(1).at(0)>ttdc->at(1).at(0)) HitRight=1;
                else HitRight=0;
            }
            if(ltdc->at(4).size()!=0 && ttdc->at(4).size()!=0){
                if(ltdc->at(4).at(0)>ttdc->at(4).at(0)) HitLeft=1;
                else HitLeft=0;
            }
            if(HitRight && HitLeft) return true;
            else return false;
        }
        else if(Strip==1){
            if(ltdc->at(0).size()!=0 && ttdc->at(0).size()!=0){
                if(ltdc->at(0).at(0)>ttdc->at(0).at(0)) HitRight=1;
                else HitRight=0;
            }
            if(ltdc->at(3).size()!=0 && ttdc->at(3).size()!=0){
                if(ltdc->at(3).at(0)>ttdc->at(3).at(0)) HitLeft=1;
                else HitLeft=0;
            }
            if(HitRight && HitLeft) return true;
            else return false;
        }
        else if(Strip==-1){
            if(ltdc->at(2).size()!=0 && ttdc->at(2).size()!=0){
                if(ltdc->at(2).at(0)>ttdc->at(2).at(0)) HitRight=1;
                else HitRight=0;
            }
            if(ltdc->at(5).size()!=0 && ttdc->at(5).size()!=0){
                if(ltdc->at(5).at(0)>ttdc->at(5).at(0)) HitLeft=1;
                else HitLeft=0;
            }
            if(HitRight && HitLeft) return true;
            else return false;
        }
        else{
            cout << RED "error: " END33 << "call of not exisiting the strip" << endl;
            Analysis:: ~Analysis();
            exit(1);
            return false;
        }
    }
}

Int_t Analysis:: GetLtdcSize(Int_t ch){
    if(BSetData) return ReconfigLtdc.at(ch).size();
    else return ltdc->at(ch).size();
}

Int_t Analysis:: GetTtdcSize(Int_t ch){
    if(BSetData) return ReconfigTtdc.at(ch).size();
    else return ttdc->at(ch).size();
}

Int_t Analysis:: GetWidthSize(Int_t ch){
    if(BSetData) return ReconfigWidth.at(ch).size();
    else return width->at(ch).size();
}

Double_t Analysis:: GetLtdc(Int_t ch, Int_t Nth=0){
    if(BSetData) return ReconfigLtdc.at(ch).at(Nth);
    else return ltdc->at(ch).at(Nth);
}

Double_t Analysis:: GetTtdc(Int_t ch, Int_t Nth=0){
    if(BSetData) return ReconfigTtdc.at(ch).at(Nth);
    else return ttdc->at(ch).at(Nth);
}

Double_t Analysis:: GetWidth(Int_t ch, Int_t Nth=0){
    if(BSetData) return ReconfigWidth.at(ch).at(Nth);
    else return ltdc->at(ch).at(Nth)-ttdc->at(ch).at(Nth);
}

Double_t Analysis:: SlewingFunction(Double_t x, Double_t *p){
    // return p[0]+p[1]/(x+p[2])+p[3]/sqrt(x+p[4]);
    return p[0]+p[1]*x+p[2]*pow(x,2)+p[3]*pow(x,3)+p[4]*pow(x,4)+p[5]*pow(x,5)+p[6]*pow(x,6)+p[7]*pow(x,7)+p[8]*pow(x,8)+p[9]*pow(x,9);
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
        while(i<nltdc && j<nttdc){
            if(i+1<nltdc && ltdc->at(ch).at(i+1)>ttdc->at(ch).at(j)) i++;
            else if(ttdc->at(ch).at(j)>ltdc->at(ch).at(i)) j++;
            else if(ltdc->at(ch).at(i)>=ttdc->at(ch).at(j)){
                ReconfigLtdc.at(ch).emplace_back(ltdc->at(ch).at(i));
                ReconfigTtdc.at(ch).emplace_back(ttdc->at(ch).at(j));
                ReconfigWidth.at(ch).emplace_back(ltdc->at(ch).at(i)-ttdc->at(ch).at(j));
                Int_t nReconfigLtdc= ReconfigLtdc.at(ch).size();
                Int_t nReconfigTtdc= ReconfigTtdc.at(ch).size();
                // cout << RED << Form("ReconfigLtdc.at(%2d).at(%2d)= ", ch, nReconfigLtdc-1) << END33 << ReconfigLtdc.at(ch).at(nReconfigLtdc-1) << endl;
                // cout << BLUE << Form("ReconfigTtdc.at(%2d).at(%2d)= ", ch, nReconfigTtdc-1) << END33 << ReconfigTtdc.at(ch).at(nReconfigTtdc-1) << endl;
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

void Analysis:: CheckData(Int_t iEntry){
    cout << MAGENTA << "Event :" << iEntry << END33 << endl;
    cout << MAGENTA "ltdc" END33 << endl;
    for(Int_t ch=0; ch<32; ch++){
        if(ch==0) cout << UL "|ch|" << "    0th|" << "    1st|" << "    2nd|" << "    3rd|" << "    4th|" << "    5th|" END33 << endl;
        cout << UL << Form("|%2d|", ch) << END33;
        for(Int_t i=0; i<ltdc->at(ch).size(); i++){
            cout << MAGENTA << setw(7) << ltdc->at(ch).at(i) << END33 << "|";
        }
        cout << endl;
    }
    cout << endl;

    cout << BLUE << "Event :" << iEntry << END33 << endl;
    cout << BLUE "ttdc" END33 << endl;
    for(Int_t ch=0; ch<32; ch++){
        if(ch==0) cout << UL "|ch|" << "    0th|" << "    1st|" << "    2nd|" << "    3rd|" << "    4th|" << "    5th|" END33 << endl;
        cout << UL << Form("|%2d|", ch) << END33;
        for(Int_t i=0; i<ttdc->at(ch).size(); i++){
            cout << BLUE << setw(7) << ttdc->at(ch).at(i) << END33 << "|";
        }
        cout << endl;
    }
    cout << endl;

    cout << YELLOW << "Event :" << iEntry << END33 << endl;
    cout << YELLOW "amp" END33 << endl;
    for(Int_t ch=0; ch<16; ch++){
        if(ch==0) cout << UL "|ch|" << "    0th|" << "    1st|" << "    2nd|" << "    3rd|" << "    4th|" << "    5th|" END33 << endl;
        cout << UL << Form("|%2d|", ch) << END33;
        for(Int_t i=0; i<amp->at(ch).size(); i++){
            cout << YELLOW << setw(7) << amp->at(ch).at(i) << END33 << "|";
        }
        cout << endl;
    }
    cout << endl;
}

void Analysis:: CheckSetData(Int_t iEntry){
    cout << MAGENTA << "Event :" << iEntry << END33 << endl;
    cout << MAGENTA "ReconfigLtdc" END33 << endl;
    for(Int_t ch=0; ch<32; ch++){
        if(ch==0) cout << UL "|ch|" << "    0th|" << "    1st|" << "    2nd|" << "    3rd|" << "    4th|" << "    5th|" END33 << endl;
        cout << UL << Form("|%2d|", ch) << END33;
        for(Int_t i=0; i<ReconfigLtdc.at(ch).size(); i++){
            cout << MAGENTA << setw(7) << ReconfigLtdc.at(ch).at(i) << END33 << "|";
        }
        cout << endl;
    }
    cout << endl;

    cout << BLUE << "Event :" << iEntry << END33 << endl;
    cout << BLUE "ReconfigTtdc" END33 << endl;
    for(Int_t ch=0; ch<32; ch++){
        if(ch==0) cout << UL "|ch|" << "    0th|" << "    1st|" << "    2nd|" << "    3rd|" << "    4th|" << "    5th|" END33 << endl;
        cout << UL << Form("|%2d|", ch) << END33;
        for(Int_t i=0; i<ReconfigTtdc.at(ch).size(); i++){
            cout << BLUE << setw(7) << ReconfigTtdc.at(ch).at(i) << END33 << "|";
        }
        cout << endl;
    }
    cout << endl;

    cout << YELLOW << "Event :" << iEntry << END33 << endl;
    cout << YELLOW "amp" END33 << endl;
    for(Int_t ch=0; ch<16; ch++){
        if(ch==0) cout << UL "|ch|" << "    0th|" << "    1st|" << "    2nd|" << "    3rd|" << "    4th|" << "    5th|" END33 << endl;
        cout << UL << Form("|%2d|", ch) << END33;
        for(Int_t i=0; i<amp->at(ch).size(); i++){
            cout << YELLOW << setw(7) << amp->at(ch).at(i) << END33 << "|";
        }
        cout << endl;
    }
    cout << endl;
}

void Analysis:: Check(){
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
        // if(ttdc->at(ch).size()<=ltdc->at(ch).size()){
        else{
            for(Int_t i=0; i<ttdc->at(ch).size(); i++){
                if(i==0) HWidth1[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
                else if(i==1) HWidth2[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
                else HWidth3[ch]-> Fill(ltdc->at(ch).at(i)-ttdc->at(ch).at(i));
            }
        }
    }
    for(Int_t ch=0; ch<16; ch++){
        for(Int_t i=0; i<amp->at(ch).size(); i++){
            // cout << Form("amp->size()= ") << amp->size() << endl;
            // cout << Form("amp->at(%d).at(%d)= ", ch, i) << amp->at(ch).at(i) << endl;
            if(i==0) HAmp1[ch]-> Fill(amp->at(ch).at(i));
            else if(i==1) HAmp2[ch]-> Fill(amp->at(ch).at(i));
            else HAmp3[ch]-> Fill(amp->at(ch).at(i));
        }
    }
    return;
}

void Analysis:: Check(Bool_t BSetData){
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
    for(Int_t ch=0; ch<16; ch++){
        for(Int_t i=0; i<amp->at(ch).size(); i++){
            if(i==0) HAmp1[ch]-> Fill(amp->at(ch).at(i));
            else if(i==1) HAmp2[ch]-> Fill(amp->at(ch).at(i));
            else HAmp3[ch]-> Fill(amp->at(ch).at(i));
        }
    }
    return;
}

void Analysis:: GetRFDist(){
    Bool_t C1= HitStrip();
    if(C1){
        Double_t right= GetLtdc(1);
        Double_t left= GetLtdc(4);
        Double_t mean= (GetLtdc(1)+GetLtdc(4))/2.;
        Double_t RFright= GetLtdc(15)-right;
        Double_t RFleft= GetLtdc(15)-left;
        Double_t RFmean= GetLtdc(15)-mean;
        HRF-> Fill(GetLtdc(15));
        HRFLtdcRight-> Fill(RFright);
        HRFLtdcLeft-> Fill(RFleft);
        HRFLtdcMean-> Fill(RFmean);
    }
}

void Analysis:: GetPeak(){
    Int_t nThreRight=20;
    Int_t nThreLeft=20;
    Int_t nThreMean=20;
    while(HRFLtdcRight->GetBinContent(iBinRight)<nThreRight) iBinRight++;
    while(HRFLtdcLeft->GetBinContent(iBinLeft)<nThreLeft) iBinLeft++;
    while(HRFLtdcMean->GetBinContent(iBinMean)<nThreMean) iBinMean++;
    CRFLtdc-> cd(1);
    HRFLtdcRight-> Fit("FRight", "Q", "", HRFLtdcRight->GetBinCenter(iBinRight)-RF/2., HRFLtdcRight->GetBinCenter(iBinRight)+RF/2.);
    CRFLtdc-> cd(2);
    HRFLtdcLeft-> Fit("FLeft", "Q", "", HRFLtdcLeft->GetBinCenter(iBinLeft)-RF/2., HRFLtdcLeft->GetBinCenter(iBinLeft)+RF/2.);
    CRFLtdc-> cd(3);
    HRFLtdcMean-> Fit("FMean", "Q", "", HRFLtdcMean->GetBinCenter(iBinMean)-RF/2., HRFLtdcMean->GetBinCenter(iBinMean)+RF/2.);
    iGaussRight= FRight->GetParameter(1);
    iGaussLeft= FLeft->GetParameter(1);
    iGaussMean= FMean->GetParameter(1);
    // cout << iGaussRight << ":" << iGaussLeft << ":" << iGaussMean << endl;
}

void Analysis:: GetTimeReso(){
    Bool_t C1= HitStrip();
    if(C1){
        Double_t right= GetLtdc(1);
        Double_t left= GetLtdc(4);
        Double_t mean= (GetLtdc(1)+GetLtdc(4))/2.;
        Double_t RFright= GetLtdc(15)-right;
        Double_t RFleft= GetLtdc(15)-left;
        Double_t RFmean= GetLtdc(15)-mean;
        for(Int_t i=0; i<80; i++){
            if(iGaussRight+RF*(2*i-1)/2.<RFright && RFright<iGaussRight+RF*(2*i+1)/2){
                HDivisionRight[i]-> Fill(RFright);
                HMergeRight-> Fill(RFright-(iGaussRight+i*RF));
                HMergeRight2D-> Fill(GetWidth(1), RFright-(iGaussRight+i*RF));
            }
            if(iGaussLeft+RF*(2*i-1)/2.<RFleft && RFleft<iGaussLeft+RF*(2*i+1)/2.){
                HDivisionLeft[i]-> Fill(RFleft);
                HMergeLeft-> Fill(RFleft-(iGaussLeft+i*RF));
                HMergeLeft2D-> Fill(GetWidth(4), RFleft-(iGaussLeft+i*RF));
            }
            if(iGaussMean+RF*(2*i-1)/2.<RFmean && RFmean<iGaussMean+RF*(2*i+1)/2.){
                HDivisionMean[i]-> Fill(RFmean);
                HMergeMean-> Fill(RFmean-(iGaussMean+i*RF));
                HMergeMeanR2D-> Fill(GetWidth(1), RFmean-(iGaussMean+i*RF));
                HMergeMeanL2D-> Fill(GetWidth(4), RFmean-(iGaussMean+i*RF));
            }
        }
    }
}

void Analysis:: GetFitFunction(){
    PMergeRight2D= HMergeRight2D-> ProfileX();
    PMergeLeft2D= HMergeLeft2D-> ProfileX();
    PMergeMeanR2D= HMergeMeanR2D-> ProfileX();
    PMergeMeanL2D= HMergeMeanL2D-> ProfileX();
    CMerge2D-> cd(1);
    FSlewingMR->SetParLimits(0, -2.0, 2.0);
    FSlewingMR->SetParLimits(9, -1.0, 1.0);
    FSlewingMR->SetParameters(0, 0, 0, 0, 0, 0, 0, 0, 0);
    PMergeRight2D-> Fit("FSlewingMR", "Q", "", 1, 11);
    CMerge2D-> cd(2);
    FSlewingML->SetParLimits(0, -2.0, 2.0);
    FSlewingML->SetParLimits(9, -1.0, 1.0);
    FSlewingML->SetParameters(0, 0, 0, 0, 0, 0, 0, 0, 0);
    PMergeLeft2D-> Fit("FSlewingML", "Q", "", 1, 11);
    CMerge2D-> cd(3);
    FSlewingMMR->SetParLimits(0, -2.0, 2.0);
    FSlewingMMR->SetParLimits(9, -1.0, 1.0);
    FSlewingMMR->SetParameters(0, 0, 0, 0, 0, 0, 0, 0, 0);
    PMergeMeanR2D-> Fit("FSlewingMMR", "Q", "", 1, 11);
    CMerge2D-> cd(4);
    FSlewingMML->SetParLimits(0, -2.0, 2.0);
    FSlewingMML->SetParLimits(9, -1.0, 1.0);
    FSlewingMML->SetParameters(0, 0, 0, 0, 0, 0, 0, 0, 0);
    PMergeMeanL2D-> Fit("FSlewingMML", "Q", "", 1, 11);
    for(Int_t i=0; i<10; i++){
        fuctorMR[i]= FSlewingMR-> GetParameter(i);
        fuctorML[i]= FSlewingML-> GetParameter(i);
        fuctorMMR[i]= FSlewingMMR-> GetParameter(i);
        fuctorMML[i]= FSlewingMML-> GetParameter(i);
    }
}

void Analysis:: GetSlewing(){
    Bool_t C1= HitStrip();
    if(C1){
        Double_t right= GetLtdc(1);
        Double_t left= GetLtdc(4);
        Double_t mean= (GetLtdc(1)+GetLtdc(4))/2.;
        Double_t RFright= GetLtdc(15)-right;
        Double_t RFleft= GetLtdc(15)-left;
        Double_t RFmean= GetLtdc(15)-mean;
        for(Int_t i=0; i<80; i++){
            if(iGaussRight+RF*(2*i-1)/2.<RFright && RFright<iGaussRight+RF*(2*i+1)/2){
                HSlewingRight-> Fill(RFright-(iGaussRight+i*RF)-SlewingFunction(GetWidth(1), fuctorMR));
                HSlewingRight2D-> Fill(GetWidth(1), RFright-(iGaussRight+i*RF)-SlewingFunction(GetWidth(1), fuctorMR));
            }
            if(iGaussLeft+RF*(2*i-1)/2.<RFleft && RFleft<iGaussLeft+RF*(2*i+1)/2.){
                HSlewingLeft-> Fill(RFleft-(iGaussLeft+i*RF)-SlewingFunction(GetWidth(4), fuctorML));
                HSlewingLeft2D-> Fill(GetWidth(4), RFleft-(iGaussLeft+i*RF)-SlewingFunction(GetWidth(4), fuctorML));
            }
            if(iGaussMean+RF*(2*i-1)/2.<RFmean && RFmean<iGaussMean+RF*(2*i+1)/2.){
                HSlewingMeanR-> Fill(RFmean-(iGaussMean+i*RF)-SlewingFunction(GetWidth(1), fuctorMMR));
                HSlewingMeanL-> Fill(RFmean-(iGaussMean+i*RF)-SlewingFunction(GetWidth(4), fuctorMML));
                HSlewingMeanR2D-> Fill(GetWidth(1), RFmean-(iGaussMean+i*RF)-SlewingFunction(GetWidth(1), fuctorMMR));
                HSlewingMeanL2D-> Fill(GetWidth(4), RFmean-(iGaussMean+i*RF)-SlewingFunction(GetWidth(4), fuctorMML));
            }
        }
    }
}

void Analysis:: GetEfficiency(){

}

void Analysis_SP8(Int_t run){
    Analysis* a= new Analysis(run);
    a-> RunEventLoop();
    a-> Save();
    return;
}

void Analysis_SP8(){
    cout << RED "error: " END33 << "enter the run number like follow example" << endl;
    cout << "\"" << RED "user$ root Analysis_SP8.cpp\\(run number\\)" END33 << "\"" << endl;
    cout << "or" << endl;
    cout << "\"" << RED "user$ root" END33 << "\"" << endl;
    cout << "\"" << RED "root [0] .x Analysis_SP8.cpp(run number)" END33 << "\"" << endl;
    exit(1);
    return;
}