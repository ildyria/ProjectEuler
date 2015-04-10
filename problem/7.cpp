#include "7.h"

bool Problem_7::is_prime(u_long n)
{
	u_long max_dividor = static_cast<u_long>(sqrt(n));

	u_long divide_by = 3;
	while(divide_by <= max_dividor)
	{
		if(n % divide_by == 0)
			return false;
		divide_by += 2;
	}

	return true;
}

void Problem_7::run()
{

	int n = 10001;
	int i = 1;
	u_long res = 1;
	while(i < n)
	{
		res += 2;
		if(is_prime(res))
		{
//			printf("%d : %ld\n", i, res);
			i++;
		}
	}

	printf("%ld\n", res);
}