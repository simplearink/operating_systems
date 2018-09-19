#!/bin/bash

if test ! -f myfile
then 
    echo 0 > myfile
fi

if ln myfile myfile.lock
	then 

		for i in `seq 1 100`
		do
		    NUMBER=`tail -1 myfile`
    		NUMBER=$((NUMBER+1))
    		echo $NUMBER >> myfile
		done
	rm myfile.lock
fi 
