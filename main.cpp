#include <iostream>
#include <stdio.h>
#include <string>
#include "includes/typedef.h"
#include "includes/args.h"
#include "includes/problem.h"
#include "includes/problem_factory.h"
#include "tools/Prime_list.h"

int main(int argc, char const *argv[])
{
	int problem_chosen = read_args(argc, argv);

	if(problem_chosen == -1)
	{
		Prime_list* primes = new Prime_list();
		primes->run();
		return 0;
	}

	Problem* pb = Problem_factory::make(problem_chosen);
	pb->run();

	delete pb;

	return 0;
}