#!/bin/bash

TEST=$1

for input_file in tests/*_input.txt; do
	echo "Izvajam ${TEST}..."
    	./dn1 tests/${TEST}_input.txt
    	diff -w out.txt tests/${TEST}_expected.txt
    	if [ $? -eq 0 ]; then
	    echo "$TEST je uspel!"
	else
	    echo "$TEST je spodletel!"
	    exit 1
	fi
done
