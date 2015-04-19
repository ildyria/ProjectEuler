#!/bin/bash
TEMPFILE='includes/problem_factory.h'
touch $TEMPFILE
rm $TEMPFILE
touch $TEMPFILE
FILE='#pragma once\n'
FILE=${FILE}'#include <iostream>\n'
FILE=${FILE}'#include <stdio.h>\n\n'
FILE=${FILE}'#include "problem.h"\n'

START_LINE_H='#include "../'
END_LINE_H='"\n'

for I in $(find problem -name "*.h" -print)
do
	FILE=${FILE}${START_LINE_H}${I}${END_LINE_H}
done

FILE=${FILE}'\n'
FILE=${FILE}'class Problem_factory\n'
FILE=${FILE}'{\n'
FILE=${FILE}'\tProblem_factory();\n'
FILE=${FILE}'\t~Problem_factory();\n'
FILE=${FILE}'public:\n'
FILE=${FILE}'\tstatic Problem* make(const int& i);\n'
FILE=${FILE}'};'

echo -e $FILE >$TEMPFILE
echo $TEMPFILE" regenerated"


TEMPFILE='includes/problem_factory.cpp'
touch $TEMPFILE
rm $TEMPFILE
touch $TEMPFILE

FILE='#include "problem_factory.h"\n'
FILE=${FILE}'\n'
FILE=${FILE}'Problem* Problem_factory::make(const int& i){\n'
FILE=${FILE}'\tprintf("problem chosen : %d\\n", i);\n'
FILE=${FILE}'\n'
FILE=${FILE}'\tswitch(i)\n'
FILE=${FILE}'\t{\n'

for I in $(find problem -name "*.h" -print)
do
	I=${I:8}
	I=${I::-2}
	FILE=${FILE}'\t\tcase '${I}':\n'
	FILE=${FILE}'\t\t\treturn new Problem_'${I}'();\n'
done
FILE=${FILE}'\t\tdefault:\n'
FILE=${FILE}'\t\t\treturn new Problem();\n'
FILE=${FILE}'\t}\n'
FILE=${FILE}'}\n'

echo -e $FILE >$TEMPFILE
echo $TEMPFILE" regenerated"

#COMMENT THIS LINE
bloody.sh make