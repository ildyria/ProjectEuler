#include "12.h"


int Problem_12::count(int n, Prime_list* p)
{
	int num_divisors = 2;
	auto prime = (*p->get()).begin();
	auto last_prime = (*p->get()).end();

	int num_curr_divisor = 1;
	while(*prime <= n && prime != last_prime)
	{
		if(n % *prime == 0)
		{
			n /= *prime;
			num_curr_divisor++;
		}
		else
		{
			num_divisors *= num_curr_divisor;
			num_curr_divisor = 1;
			++prime;
		}
	}
	if(prime == last_prime)
		std::cout << "PRIME OVERFLOW" << std::endl;
	return num_divisors;
}

void Problem_12::run()
{
	Prime_list* p = new Prime_list();
	int num = 1;
	int i = 1;
	int sum = 1;
	while(num < 500 && num != 0)
	{
		i++;
		sum += i;
		num = count(sum,p);
/*		printf("%d -- %d\n", sum, num);*/
	}
	printf("%d\n", sum);
}

