#include <iostream>
#include <stdio.h>
#include <string>
#include "includes/args.h"
#include "problem/1.cpp"

int main(int argc, char const *argv[])
{
	int problem_chosen = read_args(argc, argv);

	printf("problem chosen : %d\n", problem_chosen);

	switch(problem_chosen)
	{
		case 1:
			problem_1();
		break;
		default:
			printf("not solved yet\n");
		break;
	}

	return 0;
}