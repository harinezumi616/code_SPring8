#pragma once

class Analysis{
    private:
    Int_t Run;
    TFile *file;
    TChain *tree;
    Int_t nEntries=0;
    Int_t percent_tmp=0;
    Int_t iBinRight=1;
    Int_t iBinLeft=1;
    Int_t iBinMean=1;
    Double_t iGaussRight;
    Double_t iGaussLeft;
    Double_t iGaussMean;
    Double_t fuctorMR[5];
    Double_t fuctorML[5];
    Double_t fuctorMMR[5];
    Double_t fuctorMML[5];
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
    
    public:
    Analysis(Int_t run);
    ~Analysis();
    void Init(TChain *tree);
    void MakeCanvas1();
    void MakeCanvas2();
    void MakeCanvas3();
    void RunEventLoop();
    void DrawPlot();
    void Save();
    void indicator(Int_t iEntry, Int_t nEntries);
    void SetData();
    void CheckData(Int_t iEntry);
    void CheckSetData(Int_t iEntry);
    Bool_t HitStrip(Int_t Strip=0);
    Int_t GetLtdcSize(Int_t ch);
    Int_t GetTtdcSize(Int_t ch);
    Int_t GetWidthSize(Int_t ch);
    Double_t GetLtdc(Int_t ch, Int_t Nth=0);
    Double_t GetTtdc(Int_t ch, Int_t Nth=0);
    Double_t GetWidth(Int_t ch, Int_t Nth=0);
    Double_t SlewingFunction(Double_t x, Double_t *p);
    void Check();
    void Check(Bool_t BSetData);
    void GetRFDist();
    void GetPeak();
    void GetTimeReso();
    void GetFitFunction();
    void GetSlewing();
};