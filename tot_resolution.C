#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1F.h"
#include <vector>

void tot_resolution(double fpeak, int channel = 0, int adcch = 0)
{

  gStyle->SetOptFit(111);
  double interval = 1.9661;
 
  int TDCchR  = channel;
  int ADCchR  = adcch;
  int TDCchRF = 16;

  TFile *fin = _file0 ;
  TTree *tree = (TTree*)fin->Get("tree");

  std::vector<std::vector<double>> *amp = 0;
  std::vector<std::vector<double>> *ltdc = 0;
  std::vector<std::vector<double>> *ttdc = 0;    

  TBranch *BWaveForm = 0;
  TBranch *Bamp = 0;
  TBranch *Bltdc = 0;
  TBranch *Bttdc = 0;    
  
  tree->SetBranchAddress("amp", &amp, &Bamp );
  tree->SetBranchAddress("ltdc", &ltdc, &Bltdc );
  tree->SetBranchAddress("ttdc", &ttdc, &Bttdc );      
  
  TH1F* h0 = new TH1F("h0", "RFdT (raw)", 10000, -600, 600);
  TH1F *h1 = new TH1F("h1", "RFdt (corrected)", 100, -3, 3);
  TH2F *h2 = new TH2F("h2", "TOT v RFdT", 100, -1, 15, 100, -1, 3);
  TH2F *h3 = new TH2F("h3", "ADC v RFdT", 100, 0, 1000, 100, -3, 3);
  TH2F *h5 = new TH2F("h5", "TOT v ADC", 100, 0, 1000, 100, 0, 15);
  TH2F *h6a = new TH2F("h6a", "TOT v RFdT (corrected)", 100, -1, 15, 100, -1, 3);
  TH1F *h6  = new TH1F("h6", "TOT Slew Corrected", 100, -3, 3);
  TH2F* h7 = new TH2F("h7", "RF v RFSel", 100, -3, 3 , 10000, -600, 600);
  TH1F *h8  = new TH1F("h8", "ADC Slew Corrected", 100, -3, 3);

  h0->GetXaxis()->SetTitle("RF-Leading [ns]");
  h1->GetXaxis()->SetTitle("RF-Leading [ns] (copy)");

  h2->GetXaxis()->SetTitle("TOT [ns]");
  h2->GetYaxis()->SetTitle("Leading-RF [ns]");

  h3->GetXaxis()->SetTitle("ADC [pC]");
  h3->GetYaxis()->SetTitle("Leading-RF (corrected) [ns]");

  h5->GetXaxis()->SetTitle("ADC [pC]");
  h5->GetYaxis()->SetTitle("TOT (L-T) [ns]");

  h6->GetYaxis()->SetTitle("Entries");
  h6->GetXaxis()->SetTitle("Leading-RF (corrected) [ns]");

  h6a->GetXaxis()->SetTitle("TOT");
  h6a->GetYaxis()->SetTitle("Leading-RF (corrected) [ns]");

  h7->GetYaxis()->SetTitle("RF-Leading (raw)");
  h7->GetXaxis()->SetTitle("RF-Leading (bunched) [ns]");

  h8->GetYaxis()->SetTitle("Entries");
  h8->GetXaxis()->SetTitle("Leading-RF (corrected) [ns]");

  double Amp;  
  double TOT;
  double L;
  double T;
  double RF;
  double RFsel;
  double eff;

  int LTev = 0;
  int size_l     = 0;
  int size_trail = 0;
  int size_rf    = 0;
  int size_tot   = 0;
  
  int nRF = 0 ;
  int nL  = 0 ;
  
  int n = tree->GetEntries();

  TSpectrum * spec = new TSpectrum();

  cout << "No. of events = " << n << endl; 
  for(int i = 0; i<n; i++){

    tree->GetEntry(i);

    size_tot = ltdc->size();
    size_l = ltdc->at(TDCchR).size();    
    size_rf = ltdc->at(TDCchRF).size();
    size_trail = ttdc->at(TDCchR).size();
    
   
    if ( size_rf > 0 ) nRF ++;

    if( size_l <= 0 || size_rf <= 0 || size_trail <= 0 ) continue ;
    nL ++;


      L = ltdc->at(TDCchR).at(0);
      T = ttdc->at(TDCchR).at(0);
      Amp = amp->at(ADCchR).at(0);
      TOT = L - T;
      RF = ltdc->at(TDCchRF).at(0);

      if( L < 0 && T < 0 ) continue;

      for(int j=0; j<400; j++){
	if( fabs(RF - L - fpeak - interval*j ) < interval/2 )
	  RFsel = RF - fpeak - interval*j;
      }

      h0->Fill(RF-L);

      LTev +=1;
      h5->Fill(Amp,L-T);

      h1->Fill(RFsel - L );      
      h2->Fill(TOT, RFsel - L );

      h3->Fill(Amp, RFsel - L );
      h7->Fill( RFsel - L , RF - L ); 
  }

  eff = (double)LTev/nRF*100;
  cout << "effciency = " << eff << "%" << "  LTev: " << LTev << " nRF: " << nRF << " nL: " << nL << " n: " << n << endl;
  
  TCanvas *c0 = new TCanvas("c0","c0",3,2,1650,1100);
  c0->Divide(3,3);

  c0->cd(1);
  h0->Draw("col4");

  c0->cd(2);
  h7->Draw("col4");

  c0->cd(3);
  h1->Draw("col4");
  h1->Fit("gaus");

  c0->cd(4);
  h2->Draw("col4");

  double pTOT[3];
  double pADC[3];
  double f;

  c0->cd(5);
  TH1F * h2_pfx = (TH1F*) h2->ProfileX();
  h2_pfx->GetYaxis()->SetTitle( h2->GetYaxis()->GetTitle() );
  h2_pfx->GetXaxis()->SetTitle( h2->GetXaxis()->GetTitle() );
  h2_pfx->Draw();

  TF1 * p2 = new TF1("p2", "-([2]/(x) + [1]/sqrt(x) +[0])");
  h2_pfx->Fit("p2", "", "", 0.5, 3.5);
  h2_pfx->GetYaxis()->SetRangeUser(-0.8, 0.8 );
  p2->GetParameters(pTOT);

  c0->cd(7);
  h3->Draw("col4");
  
  c0->cd(8);
  TF1 * p2adc = new TF1("p2adc", "-([2]/(x) + [1]/sqrt(x) +[0])");
  TH1F * h3_pfx = (TH1F*) h3->ProfileX();
  h3_pfx->Fit("p2adc", "", "", 50, 600.0);
  h3_pfx->GetYaxis()->SetTitle( h5->GetYaxis()->GetTitle())  ;
  h3_pfx->Draw();
  p2adc->GetParameters(pADC);

  for(int i = 0; i< n; i++){

    tree->GetEntry(i);

    size_tot = ltdc->size();
    size_l = ltdc->at(TDCchR).size();    
    size_rf = ltdc->at(TDCchRF).size();
    size_trail = ttdc->at(TDCchR).size();
   
    if( size_l <= 0 || size_rf <= 0 || size_trail <= 0 ) continue ;

    if(size_l>0){
      L = ltdc->at(TDCchR).at(0);
      T = ttdc->at(TDCchR).at(0);
      RF = ltdc->at(TDCchRF).at(0);
      TOT = L-T;
      Amp = amp->at(ADCchR).at(0);
     
      if(L<0&&T<0) continue;
      LTev +=1;

      for(int j=0; j<400; j++){
	if( fabs(RF-L-fpeak - interval*j ) < interval/2 )
	  RFsel = RF - fpeak - interval*j;
      }

     f = -(pTOT[2]/(TOT) + pTOT[1]/sqrt(TOT) + pTOT[0]);
     h6->Fill(RFsel - L - f );
     h6a->Fill(TOT, RFsel - L - f );

     f = -(pADC[2]/(Amp) + pADC[1]/sqrt(Amp) + pADC[0]);
     h8->Fill(RFsel - L - f );
     
     }
  
  }



  c0->cd(6);
  h6->Draw("col4");
  h6->Fit("gaus");

  c0->cd(8);

  c0->cd(9);
  h8->Draw("col4");
  h8->Fit("gaus");

}
