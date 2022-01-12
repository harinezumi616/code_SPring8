#!/bin/bash
rm -i ./../Result/result.dat
echo "#run       TimeResoRight[ps]    TimeResoErrRight[ps]        TimeResoLeft[ps]     TimeResoErrLeft[ps]       TimeResoMeanR[ps]    TimeResoErrMeanR[ps]       TimeResoMeanL[ps]    TimeResoErrMeanL[ps]    TimeResoRightAmp[ps] TimeResoErrRightAmp[ps]     TimeResoLeftAmp[ps]  TimeResoErrLeftAmp[ps]    TimeResoMeanAmpR[ps] TimeResoErrMeanAmpR[ps]    TimeResoMeanAmpL[ps] TimeResoErrMeanAmpL[ps]           Efficiency[%]          EfficiencyR[%]          EfficiencyL[%]        EfficiencyAmp[%]" >> ./../Result/result.dat
echo "#MRPC1 HV scan" >> ./../Result/result.dat
for RunNo in 36 35 33 27
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC1 V_threshold scan (strip2)" >> ./../Result/result.dat
for RunNo in 45 46 47 48
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC1 V_threshold scan (strip4)" >> ./../Result/result.dat
for RunNo in 24 25 26 27 28 29 30 31 32
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC1 strip scan" >> ./../Result/result.dat
for RunNo in 51 42 41 53 55 58
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC1 position scan" >> ./../Result/result.dat
for RunNo in 72 71 55 68 72
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC2 HV scan" >> ./../Result/result.dat
for RunNo in 84 83 82 78
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC2 V_threshold scan" >> ./../Result/result.dat
for RunNo in 74 75 76 77 78 79 81
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC2 strip scan" >> ./../Result/result.dat
for RunNo in 92 94 98 100 101 102 103 104
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done

echo "#MRPC2 position scan" >> ./../Result/result.dat
for RunNo in 108 107 101 106 105
do
    timeout 180 root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done
