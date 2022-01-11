#include <iostream>
#include <string>
using namespace std;

void Scan(){
    // MRPC1
    TCanvas *CTimeResoScan1= new TCanvas("CTimeResoScan1", "CTimeResoScan1", 2000, 2000);
    TCanvas *CEffScan1= new TCanvas("CEffScan1", "CEffScan1", 2000, 2000);
    CTimeResoScan1-> Divide(2,2);
    CEffScan1-> Divide(2,2);
    // RunNo= {36, 35, 33, 27}
    Double_t HV1[4]= {11.5, 12, 12.52, 13};
    Double_t TimeResoHV1[4]= {95.9842, 86.0821, 77.6565, 78.8911};
    Double_t TimeResoHVErr1[4]= {0.78109, 0.499402, 0.45704, 0.463808};
    Double_t EffHV1[4]= {40.1683, 79.0027, 95.4828, 96.9009};

    // RunNo= {45, 46, 47,48}
    Double_t Vth1[4]= {-17.5, -35, -52.5, -70};
    Double_t TimeResoVth1[4]= {88.1479, 88.6765, 91.4172, 90.8011};
    Double_t TimeResoVthErr1[4]= {0.732578, 0.869382, 0.978207, 1.22023};
    Double_t EffVth1[4]= {51.8517, 37.4975, 29.5604, 19.704};

    // RunNo= {24, 25, 26, 27, 28, 29, 30, 31, 32}
    Double_t Vth1_strip4[9]= {-3.5, -7, -10.5, -17.5, -35, -70, -105, -140, -175};
    Double_t TimeResoVth1_strip4[9]= {};
    Double_t TimeResoVthErr1_strip4[9]= {};
    Double_t EffVth1_strip4[9]= {};
    
    // RunNo= {51, 42, 41, 53*, 55, 58}
    Double_t Strip1[6]= {1, 2, 3, 4, 5, 6};
    Double_t TimeResoStrip1[6]= {98.8717, 88.6765, 83.1457, 84.1666, 92.5224, 91.0017};
    Double_t TimeResoStripErr1[6]= {1.16067, 0.869382, 0.440485, 0.451346, 0.719804, 0.704778};
    Double_t EffStrip1[6]= {35.2879, 37.4975, 98.611, 95.1222, 55.4072, 58.3742};
    
    // RunNo= {72, 71, 54, 68, 72}
    Double_t Position1[5]= {-30, -15, 0, 15, 30};
    Double_t TimeResoPos1[5]= {99.7095, 92.345, 92.5224, 95.9285, 101.806};
    Double_t TimeResoPosErr1[5]= {1.26896, 1.21046, 0.719804, 1.39186, 1.76466};
    Double_t EffPos1[5]= {65.5831, 69.6255, 58.3742, 60.2335, 68.5894};
    
    Double_t HVErr1[4]= {};
    Double_t VthErr1[4]= {};
    Double_t StripErr1[6]= {};
    Double_t PosErr1[5]= {};



    // MRPC2
    TCanvas *CTimeResoScan2= new TCanvas("CTimeResoScan2", "CTimeResoScan2", 2000, 2000);
    TCanvas *CEffScan2= new TCanvas("CEffScan2", "CEffScan2", 2000, 2000);
    CTimeResoScan2-> Divide(2,2);
    CEffScan2-> Divide(2,2);
    // RunNo= {84, 83, 82, 78}
    Double_t HV2[4]= {11.5, 12, 12.5, 13};
    Double_t TimeResoHV2[4]= {};
    Double_t TimeResoHVErr2[4]= {};
    Double_t EffHV2[4]= {};

    // RunNo= {74, 75, 76, 77, 78, 79, 81}
    Double_t Vth2[7]= {-3.5, -7, -10.5, -17.5, -35, -70, -105};
    Double_t TimeResoVth2[7]= {};
    Double_t TimeResoVthErr2[7]= {};
    Double_t EffVth2[7]= {};

    // RunNo= {92, 94, 98, 100, 101, 102, 103, 104}
    Double_t Strip2[8]= {1, 2, 3, 4, 5, 6, 7, 8};
    Double_t TimeResoStrip2[8]= {};
    Double_t TimeResoStripErr2[8]= {};
    Double_t EffStrip2[8]= {};

    // RunNo= {108, 107, 101, 106, 105}
    Double_t Position2[5]= {-30, -15, 0, 15, 30};
    Double_t TimeResoPos2[5]= {};
    Double_t TimeResoPosErr2[5]= {};
    Double_t EffPos2[5]= {};

    Double_t HVErr2[4]= {};
    Double_t VthErr2[4]= {};
    Double_t StripErr2[6]= {};
    Double_t PosErr2[5]= {};



    TGraphErrors *GTimeResoHVScan1= new TGraphErrors(4, HV1, TimeResoHV1, HVErr1, TimeResoHVErr1);
    TGraphErrors *GTimeResoVthScan1= new TGraphErrors(4, Vth1, TimeResoVth1, VthErr1, TimeResoVthErr1);
    TGraphErrors *GTimeResoStripScan1= new TGraphErrors(6, Strip1, TimeResoStrip1, StripErr1, TimeResoStripErr1);
    TGraphErrors *GTimeResoPosScan1= new TGraphErrors(5, Position1, TimeResoPos1, PosErr1, TimeResoPosErr1);
    
    TGraphErrors *GEffHVScan1= new TGraphErrors(4, HV1, EffHV1);
    TGraphErrors *GEffVthScan1= new TGraphErrors(4, Vth1, EffVth1);
    TGraphErrors *GEffStripScan1= new TGraphErrors(6, Strip1, EffStrip1);
    TGraphErrors *GEffPosScan1= new TGraphErrors(5, Position1, EffPos1);
    
    CTimeResoScan1-> cd(1);
    GTimeResoHVScan1-> SetTitle("Time resolution; High Voltage [kV]; Time Resolution [ps]");
    GTimeResoHVScan1-> SetMarkerStyle(8);
    GTimeResoHVScan1-> SetMarkerColor(kGreen);
    GTimeResoHVScan1-> SetLineColor(kGreen);
    GTimeResoHVScan1-> Draw("apl");
    CTimeResoScan1-> cd(2);
    GTimeResoVthScan1-> SetTitle("Time resolution; Threshold Voltage [mV]; Time Resolution [ps]");
    GTimeResoVthScan1-> SetMarkerStyle(8);
    GTimeResoVthScan1-> SetMarkerColor(kGreen);
    GTimeResoVthScan1-> SetLineColor(kGreen);
    GTimeResoVthScan1-> Draw("apl");
    CTimeResoScan1-> cd(3);
    GTimeResoStripScan1-> SetTitle("Time resolution; Strip; Time Resolution [ps]");
    GTimeResoStripScan1-> SetMarkerStyle(8);
    GTimeResoStripScan1-> SetMarkerColor(kGreen);
    GTimeResoStripScan1-> SetLineColor(kGreen);
    GTimeResoStripScan1-> Draw("apl");
    CTimeResoScan1-> cd(4);
    GTimeResoPosScan1-> SetTitle("Time resolution; Position [cm]; Time Resolution [ps]");
    GTimeResoPosScan1-> SetMarkerStyle(8);
    GTimeResoPosScan1-> SetMarkerColor(kGreen);
    GTimeResoPosScan1-> SetLineColor(kGreen);
    GTimeResoPosScan1-> Draw("apl");
    CEffScan1-> cd(1);
    GEffHVScan1-> SetTitle("Efficiency; High Voltage [kV]; Efficiency [%]");
    GEffHVScan1-> SetMarkerStyle(8);
    GEffHVScan1-> SetMarkerColor(kGreen);
    GEffHVScan1-> SetLineColor(kGreen);
    GEffHVScan1-> Draw("apl");
    CEffScan1-> cd(2);
    GEffVthScan1-> SetTitle("Efficiency; Threshold Voltage [mV]; Efficiency [%]");
    GEffVthScan1-> SetMarkerStyle(8);
    GEffVthScan1-> SetMarkerColor(kGreen);
    GEffVthScan1-> SetLineColor(kGreen);
    GEffVthScan1-> Draw("apl");
    CEffScan1-> cd(3);
    GEffStripScan1-> SetTitle("Efficiency; Strip; Efficiency [%]");
    GEffStripScan1-> SetMarkerStyle(8);
    GEffStripScan1-> SetMarkerColor(kGreen);
    GEffStripScan1-> SetLineColor(kGreen);
    GEffStripScan1-> Draw("apl");
    CEffScan1-> cd(4);
    GEffPosScan1-> SetTitle("Efficiency; Position [cm]; Efficiency [%]");
    GEffPosScan1-> SetMarkerStyle(8);
    GEffPosScan1-> SetMarkerColor(kGreen);
    GEffPosScan1-> SetLineColor(kGreen);
    GEffPosScan1-> Draw("apl");
    return;
}