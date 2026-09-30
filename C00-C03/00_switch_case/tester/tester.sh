#!/bin/bash

RED='\033[0;31m'
GRN='\033[0;32m'
NC='\033[0m' # No Color

FILE=trace.txt
if [ -f $FILE ]; then
    rm $FILE
fi

cd ..
cc -Wall -Wextra -Werror rendu.c main.c -o rendu

./rendu >> tester/rendu_output.txt

cd tester
./control ../input.txt >> control_output.txt 

diff -u rendu_output.txt control_output.txt >> $FILE

rm rendu_output.txt control_output.txt

if [ -s $FILE ]; then 
    echo -e "${RED}[TESTER]: KO${NC}" 
else
    echo -e "${GRN}[TESTER]: OK${NC}"
fi
