#include "problem_factory.h"

Problem* Problem_factory::make(const int& i){
	printf("problem chosen : %d\n", i);

	switch(i)
	{
		case 1:
			return new Problem_1();
		case 2:
			return new Problem_2();
		case 3:
			return new Problem_3();
		default:
			return new Problem();
	}
}