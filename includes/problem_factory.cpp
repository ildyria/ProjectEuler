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
		case 4:
			return new Problem_4();
		case 5:
			return new Problem_5();
		case 6:
			return new Problem_6();
		default:
			return new Problem();
	}
}