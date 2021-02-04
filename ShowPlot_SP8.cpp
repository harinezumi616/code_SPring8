#include <iostream>
#include <string>
#include "Select_SP8.h"
#include "MakeCanvas_SP8.h"
using namespace std;
#define UL "\033[04m"
#define RED "\033[31m"
#define END33 "\033[m"

class ShowPlot{
    private:
    Int_t Run;
    public:
    ShowPlot(Int_t run);
    ~ShowPlot();
    void Show();
};

ShowPlot:: ShowPlot(Int_t run){
    gStyle-> SetOptFit(11111111);
    gStyle-> SetOptStat(11111111);
    TFile *fin= new TFile(Form("./../Save/run%d_plot.root", run), "read");
    if(!fin || !fin-> IsOpen()){
        cout << RED "error: " END33 << Form("can not open run%d_plot.root", run) << endl;
        exit(1);
        return;
    }
    Run= run;
    Show();
}

ShowPlot:: ~ShowPlot(){
}

void ShowPlot:: Show(){
    if(BCheck){
        CLtdc1= (TCanvas*) gROOT-> FindObject(Form("run%d_CLtdc1", Run));
        CLtdc2= (TCanvas*) gROOT-> FindObject(Form("run%d_CLtdc2", Run));
        CTtdc1= (TCanvas*) gROOT-> FindObject(Form("run%d_CTtdc1", Run));
        CTtdc2= (TCanvas*) gROOT-> FindObject(Form("run%d_CTtdc2", Run));
        CWidth1= (TCanvas*) gROOT-> FindObject(Form("run%d_CWidth1", Run));
        CWidth2= (TCanvas*) gROOT-> FindObject(Form("run%d_CWidth2", Run));
        CAmp1= (TCanvas*) gROOT-> FindObject(Form("run%d_CAmp1", Run));
        CLtdc1-> Draw();
        CLtdc2-> Draw();
        CTtdc1-> Draw();
        CTtdc2-> Draw();
        CWidth1-> Draw();
        CWidth2-> Draw();
        CAmp1-> Draw();
        for(Int_t ch=0; ch<32; ch++){
            HLtdc1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HLtdc1[%d]", Run, ch));
            HLtdc2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HLtdc2[%d]", Run, ch));
            HLtdc3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HLtdc3[%d]", Run, ch));
            HTtdc1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HTtdc1[%d]", Run, ch));
            HTtdc2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HTtdc2[%d]", Run, ch));
            HTtdc3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HTtdc3[%d]", Run, ch));
            HWidth1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HWidth1[%d]", Run, ch));
            HWidth2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HWidth2[%d]", Run, ch));
            HWidth3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HWidth3[%d]", Run, ch));
        }
        for(Int_t ch=0; ch<16; ch++){
            HAmp1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HAmp1[%d]", Run, ch));
            HAmp2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HAmp2[%d]", Run, ch));
            HAmp3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HAmp3[%d]", Run, ch));
        }
    }
    if(BGetTimeReso){
        CRF= (TCanvas*) gROOT-> FindObject(Form("run%d_CRF", Run));
        CRFLtdc= (TCanvas*) gROOT-> FindObject(Form("run%d_CRFLtdc", Run));
        for(Int_t i=0; i<3; i++){
            CDivision[i]= (TCanvas*) gROOT-> FindObject(Form("run%d_CDivision[%d]", Run, i));
            CDivision[i]-> Draw();
        }
        CMerge= (TCanvas*) gROOT-> FindObject(Form("run%d_CMerge", Run));
        CMerge2D= (TCanvas*) gROOT-> FindObject(Form("run%d_CMerge2D", Run));
        CSlewing= (TCanvas*) gROOT-> FindObject(Form("run%d_CSlewing", Run));
        CSlewing2D= (TCanvas*) gROOT-> FindObject(Form("run%d_CSlewing2D", Run));
        CRF-> Draw();
        CRFLtdc-> Draw();
        CMerge-> Draw();
        CMerge2D-> Draw();
        CSlewing-> Draw();
        CSlewing2D-> Draw();
        HRF= (TH1D*) gROOT-> FindObject(Form("run%d_HRF", Run));
        HRFLtdcRight= (TH1D*) gROOT-> FindObject(Form("run%d_HRFLtdcRight", Run));
        HRFLtdcLeft= (TH1D*) gROOT-> FindObject(Form("run%d_HRFLtdcLeft", Run));
        HRFLtdcMean= (TH1D*) gROOT-> FindObject(Form("run%d_HRFLtdcMean", Run));
        for(Int_t i=0; i<80; i++){
            HDivisionRight[i]= (TH1D*) gROOT-> FindObject(Form("run%d_HDivisionRight[%d]", Run, i));
            HDivisionLeft[i]= (TH1D*) gROOT-> FindObject(Form("run%d_HDivisionLeft[%d]", Run, i));
            HDivisionMean[i]= (TH1D*) gROOT-> FindObject(Form("run%d_HDivisionMean[%d]", Run, i));
        }
        HMergeRight= (TH1D*) gROOT-> FindObject(Form("run%d_HMergeRight", Run));
        HMergeLeft= (TH1D*) gROOT-> FindObject(Form("run%d_HMergeLeft", Run));
        HMergeMean= (TH1D*) gROOT-> FindObject(Form("run%d_HMergeMean", Run));
        HMergeRight2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeRight2D", Run));
        HMergeLeft2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeLeft2D", Run));
        HMergeMeanR2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeMeanR2D", Run));
        HMergeMeanL2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeMeanL2D", Run));
        HSlewingRight= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingRight", Run));
        HSlewingLeft= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingLeft", Run));
        HSlewingMeanR= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingMeanR", Run));
        HSlewingMeanL= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingMeanL", Run));
        HSlewingRight2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingRight2D", Run));
        HSlewingLeft2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingLeft2D", Run));
        HSlewingMeanR2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingMeanR2D", Run));
        HSlewingMeanL2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingMeanL2D", Run));
        if(BGetDifference){
            CDifference= (TCanvas*) gROOT-> FindObject(Form("run%d_CDifference", Run));
            CDifference-> Draw();
            HDifference= (TH1D*) gROOT-> FindObject(Form("run%d_HDifference", Run));
            HDiffRight= (TH2D*) gROOT-> FindObject(Form("run%d_HDiffRight", Run));
            HDiffLeft= (TH2D*) gROOT-> FindObject(Form("run%d_HDiffLeft", Run));
            HDiffMeanR= (TH2D*) gROOT-> FindObject(Form("run%d_HDiffMeanR", Run));
            HDiffMeanL= (TH2D*) gROOT-> FindObject(Form("run%d_HDiffMeanL", Run));
        }
    }
}

void ShowPlot_SP8(Int_t run){
    ShowPlot* a= new ShowPlot(run);
    return;
}

void ShowPlot_SP8(){
    cout << RED "error: " END33 << "enter the run number like follow example" << endl;
    cout << "\"" << RED "user$ root ShowPlot_SP8.cpp\\(run number\\)" END33 << "\"" << endl;
    cout << "or" << endl;
    cout << "\"" << RED "user$ root" END33 << "\"" << endl;
    cout << "\"" << RED "root [0] .x ShowPlot_SP8.cpp(run number)" END33 << "\"" << endl;
    exit(1);
    return;
}