#!/bin/bash
NUM=$(find problem -name "*.h" -print | grep problem -c)
NUM=$((NUM + 1))
echo $NUM

TEMPFILE='problem/'$NUM'.h'
touch $TEMPFILE
FILE='#pragma once\n'
FILE=${FILE}'#include "../includes/problem.h"\n'
FILE=${FILE}'\n'
FILE=${FILE}'class Problem_'$NUM
FILE=${FILE}' : public Problem\n'
FILE=${FILE}'{\n'
FILE=${FILE}'public:\n'
FILE=${FILE}'\tProblem_'$NUM
FILE=${FILE}'():Problem() {};\n'
FILE=${FILE}'\t~Problem_'$NUM
FILE=${FILE}'() {};\n'
FILE=${FILE}'\tvoid run();\n'
FILE=${FILE}'};\n'

echo -e $FILE >$TEMPFILE
echo $TEMPFILE" generated"

TEMPFILE='problem/'$NUM'.cpp'
touch $TEMPFILE
FILE='#include "'$NUM
FILE=${FILE}'.h"\n'
FILE=${FILE}'\n'
FILE=${FILE}'void Problem_'$NUM
FILE=${FILE}'::run()\n'
FILE=${FILE}'{\n'
FILE=${FILE}'\tprintf("to be solved...\\n");\n'
FILE=${FILE}'}\n'

echo -e $FILE >$TEMPFILE
echo $TEMPFILE" generated"

git add problem/$NUM.h
git add problem/$NUM.cpp