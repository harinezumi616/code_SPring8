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
    // tree-> SetBranchAddress("amp", &amp);
    // tree-> SetBranchAddress("dt", &dt);
    // tree-> SetBranchAddress("width", &width);
    // tree-> SetBranchAddress("l1_tdc", &l1_tdc);
    // tree-> SetBranchAddress("l1_tdc1", &l1_tdc1);
    // tree-> SetBranchAddress("ltdc", &ltdc);
    // tree-> SetBranchAddress("ttdc", &ttdc);
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

void Analysis_SP8(Int_t run){
    cout << "OK" << endl;
    Analysis* a= new Analysis(run);
    return;
}