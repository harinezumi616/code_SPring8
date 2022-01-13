#include <iostream>
#include <string>
using namespace std;

void Scan(){
    // MRPC1=======================================================================================================
    TCanvas *CTimeResoScan1= new TCanvas("CTimeResoScan1", "CTimeResoScan1", 2000, 2000);
    TCanvas *CEffScan1= new TCanvas("CEffScan1", "CEffScan1", 2000, 2000);
    TCanvas *CTimeResoScan1_strip4= new TCanvas("CTimeResoScan1_strip4", "CTimeResoScan1_strip4", 2000, 2000);
    CTimeResoScan1-> Divide(2,2);
    CEffScan1-> Divide(2,2);
    CTimeResoScan1_strip4-> Divide(2,2);
    // RunNo= {36, 35, 33, 27}
    Double_t HV1[4]= {11.5, 12, 12.52, 13};
    Double_t TimeResoHV1[4]= {95.7562, 86.0832, 77.6048, 78.8911};
    Double_t TimeResoHVErr1[4]= {0.778649, 0.50074, 0.458592, 0.463808};
    Double_t EffHV1[4]= {40.1683, 79.0027, 95.4828, 96.9009};
    Double_t TimeResoHV1R[4]= {135.108, 115.146, 101.911, 102.233};
    Double_t TimeResoHVErr1R[4]= {1.98543,  0.98823, 0.802621, 0.789729};
    Double_t EffHV1R[4]= {47.1324, 83.5055, 96.642, 97.7191};
    Double_t TimeResoHV1L[4]= {124.441, 110.686, 100.515, 103.172};
    Double_t TimeResoHVErr1L[4]= {1.59853, 0.906597, 0.786056, 0.80717};
    Double_t EffHV1L[4]= {42.078, 80.2484, 95.7365, 97.1219};

    // RunNo= {45, 46, 47,48}
    Double_t Vth1[4]= {-17.5, -35, -52.5, -70};
    Double_t TimeResoVth1[4]= {88.1522, 88.7648, 91.2472, 89.6941};
    Double_t TimeResoVthErr1[4]= {0.734514, 0.886124, 0.971051, 1.17677};
    Double_t EffVth1[4]= {51.8587, 37.4975, 29.5604, 19.764};
    Double_t TimeResoVth1R[4]= {111.805, 121.53, 127.42, 132.098};
    Double_t TimeResoVthErr1R[4]= {1.2425, 1.85559, 2.14365, 3.10333};
    Double_t EffVth1R[4]= {99.1983, 96.693, 89.8352, 76.5964};
    Double_t TimeResoVth1L[4]= {128.077, 134.625, 138.879, 138.552};
    Double_t TimeResoVthErr1L[4]= {1.81434, 2.50595, 2.87324, 3.77706};
    Double_t EffVth1L[4]= {52.2849, 38.5503, 31.7661, 23.4036};
    
    // RunNo= {24, 25, 26, 27, 28, 29, 30, 31, 32}
    Double_t Vth1_strip4[9]= {-3.5, -7, -10.5, -17.5, -35, -70, -105, -140, -175};
    Double_t TimeResoVth1_strip4[9]= {99.5189, 89.0944, 86.0461, 78.8911, 84.9056, 99.9106, 101.214, 99.6492, 108.663};
    Double_t TimeResoVthErr1_strip4[9]= {1.15647, 0.575075, 0.55308, 0.463808, 0.624307, 0.758409, 1.24239, 1.69822, 3.71724};
    Double_t EffVth1_strip4[9]= {99.3611, 99.0286, 98.4649, 96.9009, 89.545, 60.3621, 33.0006, 14.8807, 5.64063};
    Double_t TimeResoVth1R_strip4[9]= {108.854, 107.226, 105.611, 102.233, 106.38, 122.069, 129.519, 151.504, 190.002};
    Double_t TimeResoVthErr1R_strip4[9]= {1.4201, 0.856147, 0.841565, 0.789729, 1.05597, 1.30302, 2.51386, 5.91997, 19.9546};
    Double_t EffVth1R_strip4[9]= {99.5496, 99.3229, 98.8734, 97.7191, 92.0847, 66.9856, 39.8143, 20.5992, 9.22665};
    Double_t TimeResoVth1L_strip4[9]= {113.722, 110.183, 103.973, 103.172, 110.311, 129.577, 145.695, 167.708, 207.75};
    Double_t TimeResoVthErr1L_strip4[9]= {1.58793, 0.925914, 0.820831, 0.80717, 1.16467, 1.53178, 3.44552, 8.03158, 29.4765};
    Double_t EffVth1L_strip4[9]= {99.4134, 99.079, 98.5638, 97.1219, 90.4514, 62.5478, 34.9042, 16.4968, 6.41909};
    
    // RunNo= {51, 42, 41, 53*, 55, 58}
    Double_t Strip1[6]= {1, 2, 3, 4, 5, 6};
    Double_t TimeResoStrip1[6]= {98.8717, 82.4942, 81.5299, 84.1286, 92.5009, 90.8424};
    Double_t TimeResoStripErr1[6]= {1.16067, 0.427331, 0.655271, 0.450753, 0.724967, 0.706565};
    Double_t EffStrip1[6]= {35.2879, 97.2304, 97.3615, 45.3213, 58.3742, 61.1254};
    Double_t TimeResoStrip1R[6]= {127.413, 101.567, 107.004, 106.363, 114.753, 106.641};
    Double_t TimeResoStripErr1R[6]= {2.05008, 0.684758, 1.19552, 0.755083, 1.21067, 1.0275};
    Double_t EffStrip1R[6]= {90.7646, 97.8339, 97.507, 96.5836, 94.2325, 97.6739};
    Double_t TimeResoStrip1L[6]= { 151.61, 103.31, 100.081, 112.421, 122.33, 121.102};
    Double_t TimeResoStripErr1L[6]= {3.48058, 0.713278, 1.04016, 0.892435, 1.48524, 1.4114};
    Double_t EffStrip1L[6]= {38.3086, 97.4103, 97.8659, 45.7554, 62.5954, 63.2269};
    
    // RunNo= {72, 71, 55, 68, 72}
    Double_t Position1[5]= {-30, -15, 0, 15, 30};
    Double_t TimeResoPos1[5]= {90.951, 91.8524, 92.408, 94.8681, 90.951};
    Double_t TimeResoPosErr1[5]= {1.27177, 1.20041, 0.723491, 1.57039, 1.27177};
    Double_t EffPos1[5]= {65.5831, 69.6255, 58.3822, 60.2335, 65.5831};
    Double_t TimeResoPos1R[5]= {112.077, 111.897, 114.763, 119.41, 112.077};
    Double_t TimeResoPosErr1R[5]= {2.13112, 1.92082, 1.2107, 2.59767, 2.13112};
    Double_t EffPos1R[5]= {96.6233, 97.6025, 94.2365, 88.5371, 96.6233};
    Double_t TimeResoPos1L[5]= {115.312, 120.671, 122.293, 130.659, 115.312};
    Double_t TimeResoPosErr1L[5]= {2.20046, 2.28968, 1.48302, 3.65817, 2.20046};
    Double_t EffPos1L[5]= {67.1141, 71.1116, 62.5994, 70.0513, 67.1141};
    
    Double_t HVErr1[4]= {};
    Double_t VthErr1[4]= {};
    Double_t VthErr1_strip4[9]= {};
    Double_t StripErr1[6]= {};
    Double_t PosErr1[5]= {};

    TGraphErrors *GTimeResoHVScan1= new TGraphErrors(4, HV1, TimeResoHV1, HVErr1, TimeResoHVErr1);
    TGraphErrors *GTimeResoVthScan1= new TGraphErrors(4, Vth1, TimeResoVth1, VthErr1, TimeResoVthErr1);
    TGraphErrors *GTimeResoVthScan1_strip4= new TGraphErrors(9, Vth1_strip4, TimeResoVth1_strip4, VthErr1_strip4, TimeResoVthErr1_strip4);
    TGraphErrors *GTimeResoStripScan1= new TGraphErrors(6, Strip1, TimeResoStrip1, StripErr1, TimeResoStripErr1);
    TGraphErrors *GTimeResoPosScan1= new TGraphErrors(5, Position1, TimeResoPos1, PosErr1, TimeResoPosErr1);

    TGraphErrors *GTimeResoHVScan1R= new TGraphErrors(4, HV1, TimeResoHV1R, HVErr1, TimeResoHVErr1R);
    TGraphErrors *GTimeResoVthScan1R= new TGraphErrors(4, Vth1, TimeResoVth1R, VthErr1, TimeResoVthErr1R);
    TGraphErrors *GTimeResoVthScan1R_strip4= new TGraphErrors(9, Vth1_strip4, TimeResoVth1R_strip4, VthErr1_strip4, TimeResoVthErr1R_strip4);
    TGraphErrors *GTimeResoStripScan1R= new TGraphErrors(6, Strip1, TimeResoStrip1R, StripErr1, TimeResoStripErr1R);
    TGraphErrors *GTimeResoPosScan1R= new TGraphErrors(5, Position1, TimeResoPos1R, PosErr1, TimeResoPosErr1R);

    TGraphErrors *GTimeResoHVScan1L= new TGraphErrors(4, HV1, TimeResoHV1L, HVErr1, TimeResoHVErr1L);
    TGraphErrors *GTimeResoVthScan1L= new TGraphErrors(4, Vth1, TimeResoVth1L, VthErr1, TimeResoVthErr1L);
    TGraphErrors *GTimeResoVthScan1L_strip4= new TGraphErrors(9, Vth1_strip4, TimeResoVth1L_strip4, VthErr1_strip4, TimeResoVthErr1L_strip4);
    TGraphErrors *GTimeResoStripScan1L= new TGraphErrors(6, Strip1, TimeResoStrip1L, StripErr1, TimeResoStripErr1L);
    TGraphErrors *GTimeResoPosScan1L= new TGraphErrors(5, Position1, TimeResoPos1L, PosErr1, TimeResoPosErr1L);
    
    TGraphErrors *GEffHVScan1= new TGraphErrors(4, HV1, EffHV1);
    TGraphErrors *GEffVthScan1= new TGraphErrors(4, Vth1, EffVth1);
    TGraphErrors *GEffVthScan1_strip4= new TGraphErrors(9, Vth1_strip4, EffVth1_strip4);
    TGraphErrors *GEffStripScan1= new TGraphErrors(6, Strip1, EffStrip1);
    TGraphErrors *GEffPosScan1= new TGraphErrors(5, Position1, EffPos1);

    TGraphErrors *GEffHVScan1R= new TGraphErrors(4, HV1, EffHV1R);
    TGraphErrors *GEffVthScan1R= new TGraphErrors(4, Vth1, EffVth1R);
    TGraphErrors *GEffVthScan1R_strip4= new TGraphErrors(9, Vth1_strip4, EffVth1R_strip4);
    TGraphErrors *GEffStripScan1R= new TGraphErrors(6, Strip1, EffStrip1R);
    TGraphErrors *GEffPosScan1R= new TGraphErrors(5, Position1, EffPos1R);

    TGraphErrors *GEffHVScan1L= new TGraphErrors(4, HV1, EffHV1L);
    TGraphErrors *GEffVthScan1L= new TGraphErrors(4, Vth1, EffVth1L);
    TGraphErrors *GEffVthScan1L_strip4= new TGraphErrors(9, Vth1_strip4, EffVth1L_strip4);
    TGraphErrors *GEffStripScan1L= new TGraphErrors(6, Strip1, EffStrip1L);
    TGraphErrors *GEffPosScan1L= new TGraphErrors(5, Position1, EffPos1L);

    TMultiGraph *GMerge1= new TMultiGraph();
    TMultiGraph *GMerge2= new TMultiGraph();
    TMultiGraph *GMerge3= new TMultiGraph();
    TMultiGraph *GMerge4= new TMultiGraph();
    TMultiGraph *GMerge5= new TMultiGraph();
    TMultiGraph *GMerge6= new TMultiGraph();
    TMultiGraph *GMerge7= new TMultiGraph();
    TMultiGraph *GMerge8= new TMultiGraph();
    TMultiGraph *GMergeX= new TMultiGraph();
    TMultiGraph *GMergeY= new TMultiGraph();



    // MRPC2=======================================================================================================
    TCanvas *CTimeResoScan2= new TCanvas("CTimeResoScan2", "CTimeResoScan2", 2000, 2000);
    TCanvas *CEffScan2= new TCanvas("CEffScan2", "CEffScan2", 2000, 2000);
    CTimeResoScan2-> Divide(2,2);
    CEffScan2-> Divide(2,2);
    // RunNo= {84, 83, 82, 78}
    Double_t HV2[4]= {11.5, 12, 12.5, 13};
    Double_t TimeResoHV2[4]= {247.391, 101.776, 93.9332, 92.5169};
    Double_t TimeResoHVErr2[4]= {2302.84, 7.75633, 1.56076, 1.83357};
    Double_t EffHV2[4]= {7.96686, 23.0211, 30.8238, 52.7509};
    Double_t TimeResoHV2R[4]= {4.99592, 113.784, 121.73, 111.472};
    Double_t TimeResoHVErr2R[4]= {39.6193, 5.43837, 3.02769, 2.81737};
    Double_t EffHV2R[4]= {41.4914, 70.5145, 92.813, 96.9341};
    Double_t TimeResoHV2L[4]= {1140.92, 980.421, 157.027, 145.822};
    Double_t TimeResoHVErr2L[4]= {1011.53, 677.286, 6.48884, 5.80393};
    Double_t EffHV2L[4]= {12.2371, 27.1768, 32.2822, 53.2549};

    // RunNo= {74, 75, 76, 77, 78, 79, 81}
    Double_t Vth2[7]= {-3.5, -7, -10.5, -17.5, -35, -70, -105};
    Double_t TimeResoVth2[7]= {122.262, 115.223, 109.051, 114.691, 92.5169, 92.2849, 95.474};
    Double_t TimeResoVthErr2[7]= {1.95863, 1.91056, 1.6498, 3.37743, 1.83357, 1.84195, 2.67354};
    Double_t EffVth2[7]= {89.103, 80.0271, 73.5065, 61.7479, 52.7509, 25.6829, 13.4209};
    Double_t TimeResoVth2R[7]= {101.883, 102.02, 103.106, 107.044, 111.472, 122.063, 137.966};
    Double_t TimeResoVthErr2R[7]= {1.23442, 1.45533, 1.45122, 3.04456, 2.81737, 3.6698, 6.75474};
    Double_t EffVth2R[7]= {99.8239, 99.8278, 99.8504, 90.8309, 96.9341, 90.5284, 68.3717};
    Double_t TimeResoVth2L[7]= {133.625, 126.446, 135.497, 155.248, 145.822, 161.054, 156.857};
    Double_t TimeResoVthErr2L[7]= {2.4848, 2.45615, 2.92512, 7.56088, 5.80393, 8.08791, 11.8122};
    Double_t EffVth2L[7]= {89.2169, 80.1254, 73.6133, 64.3266, 53.2549, 27.004, 16.8935};

    // RunNo= {92, 94, 98, 100, 101, 102, 103, 104}
    Double_t Strip2[8]= {1, 2, 3, 4, 5, 6, 7, 8};
    Double_t TimeResoStrip2[8]= {89.9777, 89.8259, 89.8588, 89.7106, 89.8558, 86.5218, 86.7122, 91.5373};
    Double_t TimeResoStripErr2[8]= {1.56067, 1.13992, 0.639126, 0.636212, 0.661941, 0.610499, 0.663001, 0.857692};
    Double_t EffStrip2[8]= {41.893, 73.2529, 64.2046, 65.7516, 62.8611, 66.3697, 71.6653, 51.8324};
    Double_t TimeResoStrip2R[8]= {124.515, 112.614, 105.124, 106.736, 110.713, 103.586, 99.9082, 122.794};
    Double_t TimeResoStripErr2R[8]= {3.20968,  1.96507, 0.885171, 0.945594, 1.05133, 0.879441, 0.792552, 1.66541};
    Double_t EffStrip2R[8]= {90.6476, 97.9638, 98.2547, 95.7653, 97.4902, 98.6497, 97.7815, 98.3718};
    Double_t TimeResoStrip2L[8]= {142.127, 123.848, 126.252, 121.581, 126.881, 129.893, 124.735, 137.687};
    Double_t TimeResoStripErr2L[8]= {4.89356, 2.51541, 1.45695, 1.31785, 1.55541, 1.62993, 1.57184, 2.46765};
    Double_t EffStrip2L[8]= {46.3281, 74.1076, 64.9547, 69.1271, 63.7089, 66.9618, 73.2716, 52.3954};

    // RunNo= {108, 107, 101, 106, 105}
    Double_t Position2[5]= {-30, -15, 0, 15, 30};
    Double_t TimeResoPos2[5]= {89.6944, 85.304, 89.8558, 81.8141, 88.7865};
    Double_t TimeResoPosErr2[5]= {0.748416, 0.701295, 0.661941, 0.641317, 0.728376};
    Double_t EffPos2[5]= {57.1976, 45.6337, 62.8611, 62.3396, 61.6045};
    Double_t TimeResoPos2R[5]= {129.319, 114.011, 110.713, 116.465, 109.8};
    Double_t TimeResoPosErr2R[5]= {1.94795, 1.516, 1.05133, 1.5484, 1.21718};
    Double_t EffPos2R[5]= {57.3356, 45.7892, 97.4902, 62.3396, 61.6276};
    Double_t TimeResoPos2L[5]= {132.778, 144.732, 126.881, 130.983, 148.008};
    Double_t TimeResoPosErr2L[5]= {2.0671, 2.73947, 1.55541, 2.15441, 2.76141};
    Double_t EffPos2L[5]= {67.9289, 63.8547, 63.7089, 83.6226, 79.8748};

    Double_t HVErr2[4]= {};
    Double_t VthErr2[7]= {};
    Double_t StripErr2[8]= {};
    Double_t PosErr2[5]= {};

    TGraphErrors *GTimeResoHVScan2= new TGraphErrors(4, HV2, TimeResoHV2, HVErr2, TimeResoHVErr2);
    TGraphErrors *GTimeResoVthScan2= new TGraphErrors(7, Vth2, TimeResoVth2, VthErr2, TimeResoVthErr2);
    TGraphErrors *GTimeResoStripScan2= new TGraphErrors(8, Strip2, TimeResoStrip2, StripErr2, TimeResoStripErr2);
    TGraphErrors *GTimeResoPosScan2= new TGraphErrors(5, Position2, TimeResoPos2, PosErr2, TimeResoPosErr2);

    TGraphErrors *GTimeResoHVScan2R= new TGraphErrors(4, HV2, TimeResoHV2R, HVErr2, TimeResoHVErr2R);
    TGraphErrors *GTimeResoVthScan2R= new TGraphErrors(7, Vth2, TimeResoVth2R, VthErr2, TimeResoVthErr2R);
    TGraphErrors *GTimeResoStripScan2R= new TGraphErrors(8, Strip2, TimeResoStrip2R, StripErr2, TimeResoStripErr2R);
    TGraphErrors *GTimeResoPosScan2R= new TGraphErrors(5, Position2, TimeResoPos2R, PosErr2, TimeResoPosErr2R);
    
    TGraphErrors *GTimeResoHVScan2L= new TGraphErrors(4, HV2, TimeResoHV2L, HVErr2, TimeResoHVErr2L);
    TGraphErrors *GTimeResoVthScan2L= new TGraphErrors(7, Vth2, TimeResoVth2L, VthErr2, TimeResoVthErr2L);
    TGraphErrors *GTimeResoStripScan2L= new TGraphErrors(8, Strip2, TimeResoStrip2L, StripErr2, TimeResoStripErr2L);
    TGraphErrors *GTimeResoPosScan2L= new TGraphErrors(5, Position2, TimeResoPos2L, PosErr2, TimeResoPosErr2L);
    
    TGraphErrors *GEffHVScan2= new TGraphErrors(4, HV2, EffHV2);
    TGraphErrors *GEffVthScan2= new TGraphErrors(7, Vth2, EffVth2);
    TGraphErrors *GEffStripScan2= new TGraphErrors(8, Strip2, EffStrip2);
    TGraphErrors *GEffPosScan2= new TGraphErrors(5, Position2, EffPos2);
    
    TGraphErrors *GEffHVScan2R= new TGraphErrors(4, HV2, EffHV2R);
    TGraphErrors *GEffVthScan2R= new TGraphErrors(7, Vth2, EffVth2R);
    TGraphErrors *GEffStripScan2R= new TGraphErrors(8, Strip2, EffStrip2R);
    TGraphErrors *GEffPosScan2R= new TGraphErrors(5, Position2, EffPos2R);
    
    TGraphErrors *GEffHVScan2L= new TGraphErrors(4, HV2, EffHV2L);
    TGraphErrors *GEffVthScan2L= new TGraphErrors(7, Vth2, EffVth2L);
    TGraphErrors *GEffStripScan2L= new TGraphErrors(8, Strip2, EffStrip2L);
    TGraphErrors *GEffPosScan2L= new TGraphErrors(5, Position2, EffPos2L);

    TMultiGraph *GMerge9= new TMultiGraph();
    TMultiGraph *GMerge10= new TMultiGraph();
    TMultiGraph *GMerge11= new TMultiGraph();
    TMultiGraph *GMerge12= new TMultiGraph();
    TMultiGraph *GMerge13= new TMultiGraph();
    TMultiGraph *GMerge14= new TMultiGraph();
    TMultiGraph *GMerge15= new TMultiGraph();
    TMultiGraph *GMerge16= new TMultiGraph();



    // MRPC1=======================================================================================================
    TLegend *Legend1= new TLegend(0.7, 0.7, 0.85, 0.85);
    Legend1-> AddEntry(GTimeResoHVScan1R, "MRPC(Right)", "p");
    Legend1-> AddEntry(GTimeResoHVScan1L, "MRPC(Left)", "p");
    Legend1-> AddEntry(GTimeResoHVScan1, "MRPC(Mean)", "p");

    CTimeResoScan1-> cd(1);
    GTimeResoHVScan1-> SetMarkerStyle(8);
    GTimeResoHVScan1-> SetMarkerColor(kGreen);
    GTimeResoHVScan1-> SetLineColor(kGreen);
    GTimeResoHVScan1R-> SetMarkerStyle(8);
    GTimeResoHVScan1R-> SetMarkerColor(kRed);
    GTimeResoHVScan1R-> SetLineColor(kRed);
    GTimeResoHVScan1L-> SetMarkerStyle(8);
    GTimeResoHVScan1L-> SetMarkerColor(kBlue);
    GTimeResoHVScan1L-> SetLineColor(kBlue);
    GMerge1-> Add(GTimeResoHVScan1);
    GMerge1-> Add(GTimeResoHVScan1R);
    GMerge1-> Add(GTimeResoHVScan1L);
    GMerge1-> SetName("Time resolution (MRPC1); High Voltage [kV]; Time Resolution [ps]");
    GMerge1-> SetTitle("Time resolution (MRPC1); High Voltage [kV]; Time Resolution [ps]");
    GMerge1-> Draw("apl");
    Legend1-> Draw();
    CTimeResoScan1-> cd(2);
    GTimeResoVthScan1-> SetMarkerStyle(8);
    GTimeResoVthScan1-> SetMarkerColor(kGreen);
    GTimeResoVthScan1-> SetLineColor(kGreen);
    GTimeResoVthScan1R-> SetMarkerStyle(8);
    GTimeResoVthScan1R-> SetMarkerColor(kRed);
    GTimeResoVthScan1R-> SetLineColor(kRed);
    GTimeResoVthScan1L-> SetMarkerStyle(8);
    GTimeResoVthScan1L-> SetMarkerColor(kBlue);
    GTimeResoVthScan1L-> SetLineColor(kBlue);
    GMerge2-> Add(GTimeResoVthScan1);
    GMerge2-> Add(GTimeResoVthScan1R);
    GMerge2-> Add(GTimeResoVthScan1L);
    GMerge2-> SetName("Time resolution (MRPC1); Threshold Voltage [mV]; Time Resolution [ps]");
    GMerge2-> SetTitle("Time resolution (MRPC1); Threshold Voltage [mV]; Time Resolution [ps]");
    GMerge2-> Draw("apl");
    Legend1-> Draw();
    CTimeResoScan1-> cd(3);
    GTimeResoStripScan1-> SetMarkerStyle(8);
    GTimeResoStripScan1-> SetMarkerColor(kGreen);
    GTimeResoStripScan1-> SetLineColor(kGreen);
    GTimeResoStripScan1R-> SetMarkerStyle(8);
    GTimeResoStripScan1R-> SetMarkerColor(kRed);
    GTimeResoStripScan1R-> SetLineColor(kRed);
    GTimeResoStripScan1L-> SetMarkerStyle(8);
    GTimeResoStripScan1L-> SetMarkerColor(kBlue);
    GTimeResoStripScan1L-> SetLineColor(kBlue);
    GMerge3-> Add(GTimeResoStripScan1);
    GMerge3-> Add(GTimeResoStripScan1R);
    GMerge3-> Add(GTimeResoStripScan1L);
    GMerge3-> SetName("Time resolution (MRPC1); Strip; Time Resolution [ps]");
    GMerge3-> SetTitle("Time resolution (MRPC1); Strip; Time Resolution [ps]");
    GMerge3-> Draw("apl");
    Legend1-> Draw();
    CTimeResoScan1-> cd(4);
    GTimeResoPosScan1-> SetMarkerStyle(8);
    GTimeResoPosScan1-> SetMarkerColor(kGreen);
    GTimeResoPosScan1-> SetLineColor(kGreen);
    GTimeResoPosScan1R-> SetMarkerStyle(8);
    GTimeResoPosScan1R-> SetMarkerColor(kRed);
    GTimeResoPosScan1R-> SetLineColor(kRed);
    GTimeResoPosScan1L-> SetMarkerStyle(8);
    GTimeResoPosScan1L-> SetMarkerColor(kBlue);
    GTimeResoPosScan1L-> SetLineColor(kBlue);
    GMerge4-> Add(GTimeResoPosScan1);
    GMerge4-> Add(GTimeResoPosScan1R);
    GMerge4-> Add(GTimeResoPosScan1L);
    GMerge4-> SetName("Time resolution (MRPC1); Position [cm]; Time Resolution [ps]");
    GMerge4-> SetTitle("Time resolution (MRPC1); Position [cm]; Time Resolution [ps]");
    GMerge4-> Draw("apl");
    Legend1-> Draw();

    CEffScan1-> cd(1);
    GEffHVScan1-> SetMarkerStyle(8);
    GEffHVScan1-> SetMarkerColor(kGreen);
    GEffHVScan1-> SetLineColor(kGreen);
    GEffHVScan1R-> SetMarkerStyle(8);
    GEffHVScan1R-> SetMarkerColor(kRed);
    GEffHVScan1R-> SetLineColor(kRed);
    GEffHVScan1L-> SetMarkerStyle(8);
    GEffHVScan1L-> SetMarkerColor(kBlue);
    GEffHVScan1L-> SetLineColor(kBlue);
    GMerge5-> Add(GEffHVScan1);
    GMerge5-> Add(GEffHVScan1R);
    GMerge5-> Add(GEffHVScan1L);
    GMerge5-> SetName("Efficiency (MRPC1); High Voltage [kV]; Efficiency [%]");
    GMerge5-> SetTitle("Efficiency (MRPC1); High Voltage [kV]; Efficiency [%]");
    GMerge5-> Draw("apl");
    Legend1-> Draw();
    CEffScan1-> cd(2);
    GEffVthScan1-> SetMarkerStyle(8);
    GEffVthScan1-> SetMarkerColor(kGreen);
    GEffVthScan1-> SetLineColor(kGreen);
    GEffVthScan1R-> SetMarkerStyle(8);
    GEffVthScan1R-> SetMarkerColor(kRed);
    GEffVthScan1R-> SetLineColor(kRed);
    GEffVthScan1L-> SetMarkerStyle(8);
    GEffVthScan1L-> SetMarkerColor(kBlue);
    GEffVthScan1L-> SetLineColor(kBlue);
    GMerge6-> Add(GEffVthScan1);
    GMerge6-> Add(GEffVthScan1R);
    GMerge6-> Add(GEffVthScan1L);
    GMerge6-> SetName("Efficiency (MRPC1); Threshold Voltage [mV]; Efficiency [%]");
    GMerge6-> SetTitle("Efficiency (MRPC1); Threshold Voltage [mV]; Efficiency [%]");
    GMerge6-> Draw("apl");
    Legend1-> Draw();
    CEffScan1-> cd(3);
    GEffStripScan1-> SetMarkerStyle(8);
    GEffStripScan1-> SetMarkerColor(kGreen);
    GEffStripScan1-> SetLineColor(kGreen);
    GEffStripScan1R-> SetMarkerStyle(8);
    GEffStripScan1R-> SetMarkerColor(kRed);
    GEffStripScan1R-> SetLineColor(kRed);
    GEffStripScan1L-> SetMarkerStyle(8);
    GEffStripScan1L-> SetMarkerColor(kBlue);
    GEffStripScan1L-> SetLineColor(kBlue);
    GMerge7-> Add(GEffStripScan1);
    GMerge7-> Add(GEffStripScan1R);
    GMerge7-> Add(GEffStripScan1L);
    GMerge7-> SetName("Efficiency (MRPC1); Strip; Efficiency [%]");
    GMerge7-> SetTitle("Efficiency (MRPC1); Strip; Efficiency [%]");
    GMerge7-> Draw("apl");
    Legend1-> Draw();
    CEffScan1-> cd(4);
    GEffPosScan1-> SetMarkerStyle(8);
    GEffPosScan1-> SetMarkerColor(kGreen);
    GEffPosScan1-> SetLineColor(kGreen);
    GEffPosScan1R-> SetMarkerStyle(8);
    GEffPosScan1R-> SetMarkerColor(kRed);
    GEffPosScan1R-> SetLineColor(kRed);
    GEffPosScan1L-> SetMarkerStyle(8);
    GEffPosScan1L-> SetMarkerColor(kBlue);
    GEffPosScan1L-> SetLineColor(kBlue);
    GMerge8-> Add(GEffPosScan1);
    GMerge8-> Add(GEffPosScan1R);
    GMerge8-> Add(GEffPosScan1L);
    GMerge8-> SetName("Efficiency (MRPC1); Position [cm]; Efficiency [%]");
    GMerge8-> SetTitle("Efficiency (MRPC1); Position [cm]; Efficiency [%]");
    GMerge8-> Draw("apl");
    Legend1-> Draw();


    CTimeResoScan1_strip4-> cd(1);
    GTimeResoVthScan1_strip4-> SetMarkerStyle(8);
    GTimeResoVthScan1_strip4-> SetMarkerColor(kGreen);
    GTimeResoVthScan1_strip4-> SetLineColor(kGreen);
    GTimeResoVthScan1R_strip4-> SetMarkerStyle(8);
    GTimeResoVthScan1R_strip4-> SetMarkerColor(kRed);
    GTimeResoVthScan1R_strip4-> SetLineColor(kRed);
    GTimeResoVthScan1L_strip4-> SetMarkerStyle(8);
    GTimeResoVthScan1L_strip4-> SetMarkerColor(kBlue);
    GTimeResoVthScan1L_strip4-> SetLineColor(kBlue);
    GMergeX-> Add(GTimeResoVthScan1_strip4);
    GMergeX-> Add(GTimeResoVthScan1R_strip4);
    GMergeX-> Add(GTimeResoVthScan1L_strip4);
    GMergeX-> SetName("Time resolution (MRPC1 strip4); Threshold Voltage [mV]; Time Resolution [ps]");
    GMergeX-> SetTitle("Time resolution (MRPC1 strip4); Threshold Voltage [mV]; Time Resolution [ps]");
    GMergeX-> Draw("apl");
    Legend1-> Draw();

    CTimeResoScan1_strip4-> cd(2);
    GEffVthScan1_strip4-> SetMarkerStyle(8);
    GEffVthScan1_strip4-> SetMarkerColor(kGreen);
    GEffVthScan1_strip4-> SetLineColor(kGreen);
    GEffVthScan1R_strip4-> SetMarkerStyle(8);
    GEffVthScan1R_strip4-> SetMarkerColor(kRed);
    GEffVthScan1R_strip4-> SetLineColor(kRed);
    GEffVthScan1L_strip4-> SetMarkerStyle(8);
    GEffVthScan1L_strip4-> SetMarkerColor(kBlue);
    GEffVthScan1L_strip4-> SetLineColor(kBlue);
    GMergeY-> Add(GEffVthScan1_strip4);
    GMergeY-> Add(GEffVthScan1R_strip4);
    GMergeY-> Add(GEffVthScan1L_strip4);
    GMergeY-> SetName("Efficiency (MRPC1); Threshold Voltage [mV]; Efficiency [%]");
    GMergeY-> SetTitle("Efficiency (MRPC1); Threshold Voltage [mV]; Efficiency [%]");
    GMergeY-> Draw("apl");
    Legend1-> Draw();



    // MRPC2=======================================================================================================
    CTimeResoScan2-> cd(1);
    GTimeResoHVScan2-> SetMarkerStyle(8);
    GTimeResoHVScan2-> SetMarkerColor(kGreen);
    GTimeResoHVScan2-> SetLineColor(kGreen);
    GTimeResoHVScan2R-> SetMarkerStyle(8);
    GTimeResoHVScan2R-> SetMarkerColor(kRed);
    GTimeResoHVScan2R-> SetLineColor(kRed);
    GTimeResoHVScan2L-> SetMarkerStyle(8);
    GTimeResoHVScan2L-> SetMarkerColor(kBlue);
    GTimeResoHVScan2L-> SetLineColor(kBlue);
    GMerge9-> Add(GTimeResoHVScan2);
    GMerge9-> Add(GTimeResoHVScan2R);
    GMerge9-> Add(GTimeResoHVScan2L);
    GMerge9-> SetName("Time resolution (MRPC2); High Voltage [kV]; Time Resolution [ps]");
    GMerge9-> SetTitle("Time resolution (MRPC2); High Voltage [kV]; Time Resolution [ps]");
    GMerge9-> Draw("apl");
    Legend1-> Draw();
    CTimeResoScan2-> cd(2);
    GTimeResoVthScan2-> SetMarkerStyle(8);
    GTimeResoVthScan2-> SetMarkerColor(kGreen);
    GTimeResoVthScan2-> SetLineColor(kGreen);
    GTimeResoVthScan2R-> SetMarkerStyle(8);
    GTimeResoVthScan2R-> SetMarkerColor(kRed);
    GTimeResoVthScan2R-> SetLineColor(kRed);
    GTimeResoVthScan2L-> SetMarkerStyle(8);
    GTimeResoVthScan2L-> SetMarkerColor(kBlue);
    GTimeResoVthScan2L-> SetLineColor(kBlue);
    GMerge10-> Add(GTimeResoVthScan2);
    GMerge10-> Add(GTimeResoVthScan2R);
    GMerge10-> Add(GTimeResoVthScan2L);
    GMerge10-> SetName("Time resolution (MRPC2); Threshold Voltage [mV]; Time Resolution [ps]");
    GMerge10-> SetTitle("Time resolution (MRPC2); Threshold Voltage [mV]; Time Resolution [ps]");
    GMerge10-> Draw("apl");
    Legend1-> Draw();
    CTimeResoScan2-> cd(3);
    GTimeResoStripScan2-> SetMarkerStyle(8);
    GTimeResoStripScan2-> SetMarkerColor(kGreen);
    GTimeResoStripScan2-> SetLineColor(kGreen);
    GTimeResoStripScan2R-> SetMarkerStyle(8);
    GTimeResoStripScan2R-> SetMarkerColor(kRed);
    GTimeResoStripScan2R-> SetLineColor(kRed);
    GTimeResoStripScan2L-> SetMarkerStyle(8);
    GTimeResoStripScan2L-> SetMarkerColor(kBlue);
    GTimeResoStripScan2L-> SetLineColor(kBlue);
    GMerge11-> Add(GTimeResoStripScan2);
    GMerge11-> Add(GTimeResoStripScan2R);
    GMerge11-> Add(GTimeResoStripScan2L);
    GMerge11-> SetName("Time resolution (MRPC2); Strip; Time Resolution [ps]");
    GMerge11-> SetTitle("Time resolution (MRPC2); Strip; Time Resolution [ps]");
    GMerge11-> Draw("apl");
    Legend1-> Draw();
    CTimeResoScan2-> cd(4);
    GTimeResoPosScan2-> SetMarkerStyle(8);
    GTimeResoPosScan2-> SetMarkerColor(kGreen);
    GTimeResoPosScan2-> SetLineColor(kGreen);
    GTimeResoPosScan2R-> SetMarkerStyle(8);
    GTimeResoPosScan2R-> SetMarkerColor(kRed);
    GTimeResoPosScan2R-> SetLineColor(kRed);
    GTimeResoPosScan2L-> SetMarkerStyle(8);
    GTimeResoPosScan2L-> SetMarkerColor(kBlue);
    GTimeResoPosScan2L-> SetLineColor(kBlue);
    GMerge12-> Add(GTimeResoPosScan2);
    GMerge12-> Add(GTimeResoPosScan2R);
    GMerge12-> Add(GTimeResoPosScan2L);
    GMerge12-> SetName("Time resolution (MRPC2); Position [cm]; Time Resolution [ps]");
    GMerge12-> SetTitle("Time resolution (MRPC2); Position [cm]; Time Resolution [ps]");
    GMerge12-> Draw("apl");
    Legend1-> Draw();
    CEffScan2-> cd(1);
    GEffHVScan2-> SetMarkerStyle(8);
    GEffHVScan2-> SetMarkerColor(kGreen);
    GEffHVScan2-> SetLineColor(kGreen);
    GEffHVScan2R-> SetMarkerStyle(8);
    GEffHVScan2R-> SetMarkerColor(kRed);
    GEffHVScan2R-> SetLineColor(kRed);
    GEffHVScan2L-> SetMarkerStyle(8);
    GEffHVScan2L-> SetMarkerColor(kBlue);
    GEffHVScan2L-> SetLineColor(kBlue);
    GMerge13-> Add(GEffHVScan2);
    GMerge13-> Add(GEffHVScan2R);
    GMerge13-> Add(GEffHVScan2L);
    GMerge13-> SetName("Efficiency (MRPC2); High Voltage [kV]; Efficiency [%]");
    GMerge13-> SetTitle("Efficiency (MRPC2); High Voltage [kV]; Efficiency [%]");
    GMerge13-> Draw("apl");
    Legend1-> Draw();
    CEffScan2-> cd(2);
    GEffVthScan2-> SetMarkerStyle(8);
    GEffVthScan2-> SetMarkerColor(kGreen);
    GEffVthScan2-> SetLineColor(kGreen);
    GEffVthScan2R-> SetMarkerStyle(8);
    GEffVthScan2R-> SetMarkerColor(kRed);
    GEffVthScan2R-> SetLineColor(kRed);
    GEffVthScan2L-> SetMarkerStyle(8);
    GEffVthScan2L-> SetMarkerColor(kBlue);
    GEffVthScan2L-> SetLineColor(kBlue);
    GMerge14-> Add(GEffVthScan2);
    GMerge14-> Add(GEffVthScan2R);
    GMerge14-> Add(GEffVthScan2L);
    GMerge14-> SetName("Efficiency (MRPC2); Threshold Voltage [mV]; Efficiency [%]");
    GMerge14-> SetTitle("Efficiency (MRPC2); Threshold Voltage [mV]; Efficiency [%]");
    GMerge14-> Draw("apl");
    Legend1-> Draw();
    CEffScan2-> cd(3);
    GEffStripScan2-> SetMarkerStyle(8);
    GEffStripScan2-> SetMarkerColor(kGreen);
    GEffStripScan2-> SetLineColor(kGreen);
    GEffStripScan2R-> SetMarkerStyle(8);
    GEffStripScan2R-> SetMarkerColor(kRed);
    GEffStripScan2R-> SetLineColor(kRed);
    GEffStripScan2L-> SetMarkerStyle(8);
    GEffStripScan2L-> SetMarkerColor(kBlue);
    GEffStripScan2L-> SetLineColor(kBlue);
    GMerge15-> Add(GEffStripScan2);
    GMerge15-> Add(GEffStripScan2R);
    GMerge15-> Add(GEffStripScan2L);
    GMerge15-> SetName("Efficiency (MRPC2); Strip; Efficiency [%]");
    GMerge15-> SetTitle("Efficiency (MRPC2); Strip; Efficiency [%]");
    GMerge15-> Draw("apl");
    Legend1-> Draw();
    CEffScan2-> cd(4);
    GEffPosScan2-> SetMarkerStyle(8);
    GEffPosScan2-> SetMarkerColor(kGreen);
    GEffPosScan2-> SetLineColor(kGreen);
    GEffPosScan2R-> SetMarkerStyle(8);
    GEffPosScan2R-> SetMarkerColor(kRed);
    GEffPosScan2R-> SetLineColor(kRed);
    GEffPosScan2L-> SetMarkerStyle(8);
    GEffPosScan2L-> SetMarkerColor(kBlue);
    GEffPosScan2L-> SetLineColor(kBlue);
    GMerge16-> Add(GEffPosScan2);
    GMerge16-> Add(GEffPosScan2R);
    GMerge16-> Add(GEffPosScan2L);
    GMerge16-> SetName("Efficiency (MRPC2); Position [cm]; Efficiency [%]");
    GMerge16-> SetTitle("Efficiency (MRPC2); Position [cm]; Efficiency [%]");
    GMerge16-> Draw("apl");
    Legend1-> Draw();
    return;
}