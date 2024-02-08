#!/bin/bash

INFILE=$1
OUT_1="${INFILE}.replace"
OUT_2="sedOutput"
S1=$2
S2=$3

G="\033[32m"
R="\033[31m"
W="\033[0m"
B="\033[90m"
BW="\033[107m"

echo -e "${BW}${B}*** sed is for losers tester ***${W}";
echo -e "Compares [cpp_01/ex04] with [sed]\n${W}";

if [[ -z $S1 || -z $S2 || -z $INFILE ]]; then
	echo -e "${R}[Error]: tester need 3 arguments${W}" 1>&2
	exit 42
fi

echo -e "- Makefile";
make >/dev/null
if [[ $? -ne 0 ]]; then
	echo -e "${R}[Error]: make failed${W}" 1>&2
	exit $?
fi

echo -e "- Execution of your program";
./a.out $INFILE $2 $3
if [[ $? -ne 0 ]]; then
	exit $?
fi

echo -e "- Execution of sed\n";
<$INFILE sed "s/$S1/$S2/g" > $OUT_2

echo -e "${BW}Your program output${W}";
cat $OUT_1
echo -e "\n"
echo -e "${BW}sed output${W}";
cat $OUT_2
echo -e "\n"

diff $OUT_1 $OUT_2 >/dev/null
if [[ $? -ne 0 ]]; then
	echo -e "${R}[FAIL]${W} Different result between your program and sed"
else
	echo -e "${G}[OK]${W} The files are equal"
fi
