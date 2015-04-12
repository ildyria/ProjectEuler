#include "21.h"

void Problem_21::run()
{
	Prime_list* p = new Prime_list();
	std::vector<int> primes = *(p->get());
/*
	std::vector<int> factors = p->prime_factorisation(220);
	std::vector<int> divisors = p->divisor_list(factors);
	for (auto i : divisors)
	{
		printf("%d\n", i);
	}
*/
	int n_max = 10000;
	std::vector<int> numbers = std::vector<int>(n_max,0);

	// 1 divide 1...
	numbers[0] = -1;
	numbers[1] = -1;

	// prime number have only 1 divisor
	int pos = 1;
	while(primes[pos] < n_max)
	{
		numbers[primes[pos]] = 1;
		pos++;	
	}

	std::vector<int> c;
	std::vector<int> d;

	int sum;
	for(int i = 0; i < n_max; ++i)
	{
		if(numbers[i] == 0)
		{
			sum = 0;
			c = p->prime_factorisation(i);
			d = p->divisor_list(c);
			for(auto j : d)
			{
				sum += j;
			}
			numbers[i] = sum - i;
		}
	}
	int t1, t2;
	sum = 0;
	for (int i = 0; i < n_max; ++i)
	{
		t1 = numbers[i];
		if(t1 < n_max)
		{
			t2 = numbers[t1];
			if(t2 == i && t1 != i && t2 > 1 )
				{
/*
					printf("--------------\n");
					printf("%d  - %d\n", i,t1);
					printf("%d  - %d\n", t1, t2);
*/
					sum += i;	
				}
		}
	}
	printf("%d\n", sum);
}

