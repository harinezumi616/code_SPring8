#pragma once

class Analysis{
    public:
    Int_t Run;
    TFile *file;
    TChain *tree;
    Int_t nEntries=0;
    Int_t percent_tmp=0;
    vector<vector<Double_t>> ReconfigLtdc;
    vector<vector<Double_t>> ReconfigTtdc;
    vector<vector<Double_t>> ReconfigWidth;
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

    Analysis(Int_t run);
    ~Analysis();
    void Init(TChain *tree);
    void MakeCanvas();
    void RunEventLoop();
    void DrawPlot();
    void Save();
    void indicator(Int_t iEntry, Int_t nEntries);
    void SetData();
    Bool_t HitStrip(Int_t Strip=0);
    Double_t GetLtdc(Int_t ch, Int_t Nth=0);
    Double_t GetTtdc(Int_t ch, Int_t Nth=0);
    Double_t GetWidth(Int_t ch, Int_t Nth=0);
    void Check();
    void Check(Bool_t BSetData);
    void GetTimeReso();
};