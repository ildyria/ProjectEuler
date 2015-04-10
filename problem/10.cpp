#include "10.h"

bool Problem_10::is_prime(int n)
{
	int max_dividor = static_cast<int>(sqrt(n));

	int divide_by = 3;
	while(divide_by <= max_dividor)
	{
		if(n % divide_by == 0)
			return false;
		divide_by += 2;
	}

	return true;
}

void Problem_10::run()
{
	int n = 2000000;
	int i = 3;
	u_long res = 2;
	while(i < n)
	{
		if(is_prime(i))
		{
			res += i;
		}
		i += 2;
	}
	printf("%ld\n", res);
}