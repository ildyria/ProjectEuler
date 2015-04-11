#include "problem_factory.h"

Problem* Problem_factory::make(const int& i){
	printf("problem chosen : %d\n", i);

	switch(i)
	{
		case 1:
			return new Problem_1();
		case 10:
			return new Problem_10();
		case 11:
			return new Problem_11();
		case 12:
			return new Problem_12();
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
		case 7:
			return new Problem_7();
		case 8:
			return new Problem_8();
		case 9:
			return new Problem_9();
		default:
			return new Problem();
	}
}

