#include <iostream>
#include <string>
#include "Select_SP8.h"
#include "MakeCanvas_SP8.h"
using namespace std;

void ShowPlot_SP8(Int_t run){
    gStyle-> SetOptFit(11111111);
    gStyle-> SetOptStat(11111111);
    TFile *fin= new TFile(Form("./../Save/run%d_plot.root", run), "read");
    if(!fin || !fin-> IsOpen()){
        cout << Form("can not open run%d_plot.root", run) << endl;
        return;
    }
    if(BCheck){
        CLtdc1= (TCanvas*) gROOT-> FindObject(Form("run%d_CLtdc1", run));
        CLtdc2= (TCanvas*) gROOT-> FindObject(Form("run%d_CLtdc2", run));
        CTtdc1= (TCanvas*) gROOT-> FindObject(Form("run%d_CTtdc1", run));
        CTtdc2= (TCanvas*) gROOT-> FindObject(Form("run%d_CTtdc2", run));
        CWidth1= (TCanvas*) gROOT-> FindObject(Form("run%d_CWidth1", run));
        CWidth2= (TCanvas*) gROOT-> FindObject(Form("run%d_CWidth2", run));
        CAmp1= (TCanvas*) gROOT-> FindObject(Form("run%d_CAmp1", run));
        CLtdc1-> Draw();
        CLtdc2-> Draw();
        CTtdc1-> Draw();
        CTtdc2-> Draw();
        CWidth1-> Draw();
        CWidth2-> Draw();
        CAmp1-> Draw();
        for(Int_t ch=0; ch<32; ch++){
            HLtdc1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HLtdc1[%d]", run, ch));
            HLtdc2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HLtdc2[%d]", run, ch));
            HLtdc3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HLtdc3[%d]", run, ch));
            HTtdc1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HTtdc1[%d]", run, ch));
            HTtdc2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HTtdc2[%d]", run, ch));
            HTtdc3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HTtdc3[%d]", run, ch));
            HWidth1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HWidth1[%d]", run, ch));
            HWidth2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HWidth2[%d]", run, ch));
            HWidth3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HWidth3[%d]", run, ch));
        }
        for(Int_t ch=0; ch<16; ch++){
            HAmp1[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HAmp1[%d]", run, ch));
            HAmp2[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HAmp2[%d]", run, ch));
            HAmp3[ch]= (TH1D*) gROOT-> FindObject(Form("run%d_HAmp3[%d]", run, ch));
        }
    }
    if(BGetTimeReso){
        CRF= (TCanvas*) gROOT-> FindObject(Form("run%d_CRF", run));
        CRFLtdc= (TCanvas*) gROOT-> FindObject(Form("run%d_CRFLtdc", run));
        for(Int_t i=0; i<3; i++){
            CDivision[i]= (TCanvas*) gROOT-> FindObject(Form("run%d_CDivision[%d]", run, i));
            CDivision[i]-> Draw();
        }
        CMerge= (TCanvas*) gROOT-> FindObject(Form("run%d_CMerge", run));
        CMerge2D= (TCanvas*) gROOT-> FindObject(Form("run%d_CMerge2D", run));
        CSlewing= (TCanvas*) gROOT-> FindObject(Form("run%d_CSlewing", run));
        CSlewing2D= (TCanvas*) gROOT-> FindObject(Form("run%d_CSlewing2D", run));
        CRF-> Draw();
        CRFLtdc-> Draw();
        CMerge-> Draw();
        CMerge2D-> Draw();
        CSlewing-> Draw();
        CSlewing2D-> Draw();
        HRF= (TH1D*) gROOT-> FindObject(Form("run%d_HRF", run));
        HRFLtdcRight= (TH1D*) gROOT-> FindObject(Form("run%d_HRFLtdcRight", run));
        HRFLtdcLeft= (TH1D*) gROOT-> FindObject(Form("run%d_HRFLtdcLeft", run));
        HRFLtdcMean= (TH1D*) gROOT-> FindObject(Form("run%d_HRFLtdcMean", run));
        for(Int_t i=0; i<80; i++){
            HDivisionRight[i]= (TH1D*) gROOT-> FindObject(Form("run%d_HDivisionRight[%d]", run, i));
            HDivisionLeft[i]= (TH1D*) gROOT-> FindObject(Form("run%d_HDivisionLeft[%d]", run, i));
            HDivisionMean[i]= (TH1D*) gROOT-> FindObject(Form("run%d_HDivisionMean[%d]", run, i));
        }
        HMergeRight= (TH1D*) gROOT-> FindObject(Form("run%d_HMergeRight", run));
        HMergeLeft= (TH1D*) gROOT-> FindObject(Form("run%d_HMergeLeft", run));
        HMergeMean= (TH1D*) gROOT-> FindObject(Form("run%d_HMergeMean", run));
        HMergeRight2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeRight2D", run));
        HMergeLeft2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeLeft2D", run));
        HMergeMeanR2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeMeanR2D", run));
        HMergeMeanL2D= (TH2D*) gROOT-> FindObject(Form("run%d_HMergeMeanL2D", run));
        HSlewingRight= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingRight", run));
        HSlewingLeft= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingLeft", run));
        HSlewingMeanR= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingMeanR", run));
        HSlewingMeanL= (TH1D*) gROOT-> FindObject(Form("run%d_HSlewingMeanL", run));
        HSlewingRight2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingRight2D", run));
        HSlewingLeft2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingLeft2D", run));
        HSlewingMeanR2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingMeanR2D", run));
        HSlewingMeanL2D= (TH2D*) gROOT-> FindObject(Form("run%d_HSlewingMeanL2D", run));
    }
}