#!/bin/bash
rm -if ./../Result/result.dat
echo "#run    TimeResoRight[ps] TimeResoErrRight[ps]     TimeResoLeft[ps]  TimeResoErrLeft[ps]    TimeResoMeanR[ps] TimeResoErrMeanR[ps]    TimeResoMeanL[ps] TimeResoErrMeanL[ps]        Efficiency[%]" >> ./../Result/result.dat
for RunNo in {25..26}
do
    root -l -b -q Analysis_SP8.cpp\(${RunNo}\)
done