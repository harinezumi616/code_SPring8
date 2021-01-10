#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define RF 1.966



void TimeResolution(Int_t run){
    TFile *file= new TFile(Form("./../../Data/run%06d_0.root", run), "read");
    if(!file || !file-> IsOpen()){
        cout << Form("can not open run%06d_0.root", run) << endl;
        return;
    }
    TChain *tree= (TChain*)file-> Get("tree");
    gStyle-> SetOptFit(11111111);
    gStyle-> SetOptStat(11111111);
    
    vector<vector<Double_t>> *amp= 0;
    vector<vector<Double_t>> *ltdc= 0;
    vector<vector<Double_t>> *ttdc= 0;
    vector<vector<Double_t>> *width= 0;

    tree-> SetBranchAddress("amp", &amp);
    tree-> SetBranchAddress("ltdc", &ltdc);
    tree-> SetBranchAddress("ttdc", &ttdc);
    tree-> SetBranchAddress("width", &width);

    Int_t nEntries= tree-> GetEntriesFast();
    cout << "Data File: " << Form("run%06d_0.root", run) << endl;
    cout << "Event    : " << nEntries << endl;






    // for(Int_t ch=0; ch<32; ch++){
    //     Int_t i=0;
    //     Int_t j=0;
    //     width->emplace_back();
    //     Int_t nltdc= ltdc->at(ch).size();
    //     Int_t nttdc= ttdc->at(ch).size();
    //     while(i<nltdc-1 && j<nttdc){
    //         if(ltdc->at(ch).at(i+1)>ttdc->at(ch).at(j)) i++;
    //         else if(ttdc->at(ch).at(j)>ltdc->at(ch).at(i)) j++;
    //         else if(ltdc->at(ch).at(i)>ttdc->at(ch).at(j) && ttdc->at(ch).at(j)>=ltdc->at(ch).at(i+1)){
    //             // ltdc.at(ch).emplace_back(ltdc->at(ch).at(i));
    //             // ttdc.at(ch).emplace_back(ttdc->at(ch).at(j));
    //             width->at(ch).emplace_back(ltdc->at(ch).at(i) - ttdc->at(ch).at(j));
    //             // cout << Form("ltdc.at(%2d).at(%2d)= ", ch, i) << ltdc.at(ch).at(i) << endl;
    //             // cout << Form("ttdc.at(%2d).at(%2d)= ", ch, j) << ttdc.at(ch).at(j) << endl;
    //             i++;
    //             j++;
    //         }
    //         else{
    //             // cout << ch << ":" << ltdc->at(ch).at(i+1) << ":" << ttdc->at(ch).at(j) << ":" << ltdc->at(ch).at(i) <<endl;
    //             i++;
    //         }
    //     }
    // }








    TCanvas *Cltdc1= new TCanvas("Cltdc1", "Cltdc1", 2000, 2000);
    TCanvas *Cltdc2= new TCanvas("Cltdc2", "Cltdc2", 2000, 2000);
    TCanvas *Cttdc1= new TCanvas("Cttdc1", "Cttdc1", 2000, 2000);
    TCanvas *Cttdc2= new TCanvas("Cttdc2", "Cttdc2", 2000, 2000);
    TCanvas *Cwidth1= new TCanvas("Cwidth1", "Cwidth1", 2000, 2000);
    TCanvas *Cwidth2= new TCanvas("Cwidth2", "Cwidth2", 2000, 2000);
    Cltdc1-> Divide(4,4);
    Cltdc2-> Divide(4,4);
    Cttdc1-> Divide(4,4);
    Cttdc2-> Divide(4,4);
    Cwidth1-> Divide(4,4);
    Cwidth2-> Divide(4,4);
    TCanvas *C1= new TCanvas("C1", "C1", 2000, 2000);
    TCanvas *C2= new TCanvas("C2", "C2", 2000, 2000);
    TCanvas *C3= new TCanvas("C3", "C3", 2000, 2000);
    C1-> Divide(1,2);
    C2-> Divide(9,9);
    C3-> Divide(2,1);

    TH1D *Hltdc1[32];
    TH1D *Hltdc2[32];
    TH1D *Hltdc3[32];
    TH1D *Httdc1[32];
    TH1D *Httdc2[32];
    TH1D *Httdc3[32];
    TH1D *Hwidth[32];
    for(Int_t ch=0; ch<32; ch++){
        Hltdc1[ch]= new TH1D(Form("Hltdc1[%d]", ch), Form("run%d_Hltdc[%d]", run, ch), 2500, 0, 250);
        Hltdc2[ch]= new TH1D(Form("Hltdc2[%d]", ch), Form("run%d_Hltdc[%d]", run, ch), 2500, 0, 250);
        Hltdc3[ch]= new TH1D(Form("Hltdc3[%d]", ch), Form("run%d_Hltdc[%d]", run, ch), 2500, 0, 250);
        Httdc1[ch]= new TH1D(Form("Httdc1[%d]", ch), Form("run%d_Httdc[%d]", run, ch), 2500, 0, 250);
        Httdc2[ch]= new TH1D(Form("Httdc2[%d]", ch), Form("run%d_Httdc[%d]", run, ch), 2500, 0, 250);
        Httdc3[ch]= new TH1D(Form("Httdc3[%d]", ch), Form("run%d_Httdc[%d]", run, ch), 2500, 0, 250);
        Hltdc1[ch]-> SetLineColor(kRed);
        Hltdc2[ch]-> SetLineColor(kBlue);
        Hltdc3[ch]-> SetLineColor(kBlack);
        Httdc1[ch]-> SetLineColor(kRed);
        Httdc2[ch]-> SetLineColor(kBlue);
        Httdc3[ch]-> SetLineColor(kBlack);
    }
    TH1D *H1= new TH1D("H1", "H1", 9000, 350, 650);
    TH1D *H2[81];
    for(Int_t i=0; i<81; i++){
        H2[i]= new TH1D(Form("H[%d]", i), Form("H[%d]", i), 200, 401.3+RF*(2*i-1)/2., 401.3+RF*(2*i+1)/2.);
    }
    TH1D *H3= new TH1D("H3", "H3", 200, -RF/2., RF/2.);
    TH2D *H4= new TH2D("H4", "H4", 50, 0, 50, 200, -RF/2., RF/2.);



    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
        tree-> GetEntry(iEntry);
        for(Int_t ch=0; ch<32; ch++){
            // if(ltdc->at(ch).size()!=0) Hltdc[ch]-> Fill(ltdc->at(ch).at(0));
            // cout << ch << " : " << ltdc->at(ch).size() << endl;
            for(Int_t i=0; i<ltdc->at(ch).size(); i++){
                if(i==0) Hltdc1[ch]-> Fill(ltdc->at(ch).at(i));
                else if(i==1) Hltdc2[ch]-> Fill(ltdc->at(ch).at(i));
                else Hltdc3[ch]-> Fill(ltdc->at(ch).at(i));
            }

            for(Int_t i=0; i<ttdc->at(ch).size(); i++){
                if(i==0) Httdc1[ch]-> Fill(ttdc->at(ch).at(i));
                else if(i==1) Httdc2[ch]-> Fill(ttdc->at(ch).at(i));
                else Httdc3[ch]-> Fill(ttdc->at(ch).at(i));
            }
        }

        Double_t mean;
        Double_t RFmean;
        if(ltdc->at(1).size()!=0 && ltdc->at(4).size()!=0){
            mean= (ltdc->at(1).at(0) + ltdc->at(4).at(0))/2.;
            RFmean= ltdc->at(15).at(0) - mean;
            H1-> Fill(RFmean);
            for(Int_t i=0; i<81; i++){
                if(RFmean<401.3+RF*(2*i+1)/2.){
                    H2[i]-> Fill(RFmean);
                }
            }
        }
    }

    Double_t Gmean[81];
    TF1 *Fgaus[81];
    for(Int_t i=0; i<81; i++){
        Fgaus[i]= new TF1(Form("Fgaus[%d]", i), "gaus");
        H2[i]-> Fit(Form("Fgaus[%d]", i), "Q", "", 401.3+RF*(2*i-1)/2., 401.3+RF*(2*i+1)/2.);
        Gmean[i]= Fgaus[i]-> GetParameter(1);
    }

    for(Int_t iEntry=0; iEntry<nEntries; iEntry++){
        tree-> GetEntry(iEntry);
        Double_t mean;
        Double_t RFmean;
        if(ltdc->at(1).size()!=0 && ltdc->at(4).size()!=0){
            mean= (ltdc->at(1).at(0) + ltdc->at(4).at(0))/2.;
            RFmean= ltdc->at(15).at(0) - mean;
            for(Int_t i=0; i<81; i++){
                if(RFmean<401.3+RF*(2*i+1)/2.){
                    H3-> Fill(RFmean-Gmean[i]);
                    if(ttdc->at(1).size()!=0 && ttdc->at(4).size()!=0){
                        Double_t TOT= ltdc->at(1).at(0) - ttdc->at(1).at(0);
                        H4-> Fill(TOT, RFmean-Gmean[i]);
                    }
                }
            }
        }
    }
    H3-> Fit("gaus");



    for(Int_t ch=0; ch<32; ch++){
        if(ch<16){
            Cltdc1-> cd(ch+1);
            Hltdc1[ch]-> Draw();
            Hltdc2[ch]-> Draw("same");
            Hltdc3[ch]-> Draw("same");
            Cttdc1-> cd(ch+1);
            Httdc1[ch]-> Draw();
            Httdc2[ch]-> Draw("same");
            Httdc3[ch]-> Draw("same");
        }
        else{
            Cltdc2-> cd(ch-15);
            Hltdc1[ch]-> Draw();
            Hltdc2[ch]-> Draw("same");
            Hltdc3[ch]-> Draw("same");
            Cttdc2-> cd(ch-15);
            Httdc1[ch]-> Draw();
            Httdc2[ch]-> Draw("same");
            Httdc3[ch]-> Draw("same");
        }
    }

    C1-> cd(1);
    H1-> Draw();
    for(Int_t i=0; i<81; i++){
        C2-> cd(i+1);
        H2[i]-> Draw();
    }
    C3-> cd(1);
    H3-> Draw();
    C3-> cd(2);
    H4-> Draw("colz");

    return;
}