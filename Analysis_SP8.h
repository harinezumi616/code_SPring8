#pragma once

class Analysis{
    public:
    Int_t Run;
    TFile *file;
    TChain *tree;
    Int_t nEntries=0;
    Int_t percent_tmp=0;
    vector<vector<Double_t>> *amp;
    vector<vector<Double_t>> *dt;
    vector<vector<Double_t>> *width;
    Int_t l1_tdc;
    Int_t l1_tdc1;
    vector<vector<Double_t>> *ltdc;
    vector<vector<Double_t>> *ttdc;
    TBranch *b_amp;
    TBranch *b_dt;
    TBranch *b_width;
    TBranch *b_l1_tdc;
    TBranch *b_l1_tdc1;
    TBranch *b_ltdc;
    TBranch *b_ttdc;

    Analysis_SP8(Int_t run);
    ~Analysis_SP8();
    void Init(TChain *tree);
    void indicator(Int_t iEntry, Int_t nEntries);
    void MakeCanvas();
    void RunEventLoop();
    void DrawPlot();
    void Save();
};