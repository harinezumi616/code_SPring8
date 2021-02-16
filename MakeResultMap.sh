#!/bin/bash
rm -i ./../Result/result.dat
echo "#run       TimeResoRight[ps]    TimeResoErrRight[ps]        TimeResoLeft[ps]     TimeResoErrLeft[ps]       TimeResoMeanR[ps]    TimeResoErrMeanR[ps]       TimeResoMeanL[ps]    TimeResoErrMeanL[ps]    TimeResoRightAmp[ps] TimeResoErrRightAmp[ps]     TimeResoLeftAmp[ps]  TimeResoErrLeftAmp[ps]    TimeResoMeanAmpR[ps] TimeResoErrMeanAmpR[ps]    TimeResoMeanAmpL[ps] TimeResoErrMeanAmpL[ps]           Efficiency[%]        EfficiencyAmp[%]" >> ./../Result/result.dat
for RunNo in {25..38}
do
    timeout 90 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done