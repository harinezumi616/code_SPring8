#pragma once

class Analysis{
    public:
    Int_t Run;
    TFile *file;
    TChain *tree;
    Int_t nEntries=0;
    Int_t percent_tmp=0;
    vector<vector<Double_t>> RecofigLtdc;
    vector<vector<Double_t>> RecofigTtdc;
    vector<vector<Double_t>> RecofigWidth;
    vector<vector<Double_t>> *amp=0;
    vector<vector<Double_t>> *dt=0;
    vector<vector<Double_t>> *width=0;
    Int_t l1_tdc;
    Int_t l1_tdc1;
    vector<vector<Double_t>> *ltdc=0;
    vector<vector<Double_t>> *ttdc=0;
    TBranch *b_amp;
    TBranch *b_dt;
    TBranch *b_width;
    TBranch *b_l1_tdc;
    TBranch *b_l1_tdc1;
    TBranch *b_ltdc;
    TBranch *b_ttdc;
    Bool_t BCheck=0;

    Analysis(Int_t run);
    ~Analysis();
    void Init(TChain *tree);
    void Select();
    void MakeCanvas();
    void RunEventLoop();
    void DrawPlot();
    void Save();
    void indicator(Int_t iEntry, Int_t nEntries);
    void SetData();
    void Check();
};