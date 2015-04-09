#include "3.h"

void Problem_3::run()
{
	u_long num = 600851475143;
	u_long divide_by = 3;
	u_long max_divider = divide_by;
	while(num > 1)
	{
		if(num % divide_by == 0)
		{
			num /= divide_by;
			max_divider = divide_by;
		}
		else
		{
			divide_by += 2;
		}
	}

	printf("%ld\n", max_divider);
}