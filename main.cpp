#include <iostream>
#include <stdio.h>
#include <string>
#include "includes/typedef.h"
#include "includes/args.h"
#include "includes/problem.h"
#include "includes/problem_factory.h"
#include "tools/prime_list.h"
#include "tools/big_int.h"
#include "tools/Timer.h"

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

	Timer t = Timer();
	t.start();
	pb->run();
	t.stop();

	printf("done in : %.3lf ms\n", t.resultmus()/1000.0);
	delete pb;

	return 0;
}