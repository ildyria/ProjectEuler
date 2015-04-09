#include "2.h"

void Problem_2::run();
{
	int sum = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if(i % 5 == 0 || i % 3 == 0)
			sum += i;
	}
	printf("%d\n", sum);
}
