#!/bin/bash

if test ! -f myfile
then 
    echo 0 > myfile
fi

for i in `seq 1 100`
do
    NUMBER=`tail -1 myfile`
    NUMBER=$((NUMBER+1))
    echo $NUMBER >> myfile
done
