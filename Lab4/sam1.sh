#!/bin/bash
declare -a data
j=0
echo -n "Entered input is ... "
for i in "$@";
do
data[$j]=$i
((j++))
echo -n $i " "
done
echo ""
echo ${data[@]}

