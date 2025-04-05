#!/bin/bash

#Test 1
echo "Izvajam test 1..."
./dn1 tests/test1_input.txt
diff -w out.txt tests/test1_expected.txt
if [ $? -eq 0 ]; then
    echo "Test 1 je uspel!"
else
    echo "Test 1 je spodletel!"
    exit 1
fi

#Test 2
echo "Izvajam test 2..."
./dn1 tests/test2_input.txt
diff -w out.txt tests/test2_expected.txt
if [ $? -eq 0 ]; then
    echo "Test 2 je uspel!"
else
    echo "Test 2 je spodletel!"
    exit 1
fi

#Test 3
echo "Izvajam test 3..."
./dn1 tests/test3_input.txt
diff -w out.txt tests/test3_expected.txt
if [ $? -eq 0 ]; then
    echo "Test 3 je uspel!"
else
    echo "Test 3 je spodletel!"
    exit 1
fi
