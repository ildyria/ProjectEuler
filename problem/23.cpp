#include "23.h"

void Problem_23::run()
{
	Prime_list* p = new Prime_list();
	u_int size_n = 28123;
	std::vector<bool> is_abundant = std::vector<bool>(size_n + 1,false);
	std::vector<bool> is_sum_abundant = std::vector<bool>(size_n + 1,false);
	std::vector<int> prime_factors;
	std::vector<int> divisors;
	u_int sum_divisors;
	for (u_int i = 4; i <= size_n; ++i)
	{
		prime_factors = p->prime_factorisation(i);
		divisors = p->divisor_list(prime_factors);
		sum_divisors = 0;
		for (u_int j = 0; j < divisors.size(); ++j)
		{
			sum_divisors += divisors[j];
		}
		sum_divisors -= i;
		is_abundant[i] = (i < sum_divisors);
	}

	for (u_int i = 1; i <= size_n; ++i)
	{
		for (u_int a = 1; a < i; ++a)
		{
			u_int b = i - a;
			if(is_abundant[a] && is_abundant[b])
			{
				is_sum_abundant[i] = true;
				break;
			}
		}
	}

	u_long total_sum = 0;
	for (u_int i = 0; i <= size_n; ++i)
	{
		if(!is_sum_abundant[i])
			total_sum += i;
	}

	printf("%ld\n", total_sum);
}

