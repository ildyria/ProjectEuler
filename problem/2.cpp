#include "2.h"

void Problem_2::run()
{
	int sum = 0;

	int u0 = 0;
	int u1 = 1;
	int temp;
	while(u1  <= 4000000)
	{
		temp = u1;
		u1 += u0;
		u0 = temp; 
		if(u1 % 2 == 0)
			sum += u1;
	}
	printf("%d\n", sum);
}