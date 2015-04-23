#include "16.h"


void Problem_16::run()
{
	const short lookup1[] = {0,2,4,6,8,0,2,4,6,8};
	const short lookup2[] = {0,0,0,0,0,1,1,1,1,1};
	std::vector<short> num = std::vector<short>(1000,0);
	num[0] = 1;
	int decimal = 0;
	for (short i = 0; i < 1000; ++i)
	{
		for (int j = decimal; j >= 0; --j)
		{
			num[j+1] += lookup2[num[j]];
			num[j] = lookup1[num[j]];
		}
		if(num[decimal + 1] > 0) decimal++;
	}

	// printf("%d\n", decimal);
	short sum = 0;
	for (int i = decimal; i >= 0; --i)
	{
		sum += num[i];
		// printf("%d", num[i]);
	}
	// printf("\n");
	printf("%d\n", sum);
}