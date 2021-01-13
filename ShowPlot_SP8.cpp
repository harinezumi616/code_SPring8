#include <iostream>
#include <string>
#include "MakeCanvas_SP8.h"
#include "Select_SP8.h"
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
        CLtdc1-> Draw();
        CLtdc2-> Draw();
        CTtdc1-> Draw();
        CTtdc2-> Draw();
        CWidth1-> Draw();
        CWidth2-> Draw();
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
    }
}