#include "27.h"

long calc(int a, int b, int n)
{
	return n * (n + a) + b;
}

bool find_prime(std::vector<int>& primes, long prime_candidate)
{
	auto p = primes.begin();
	while(p != primes.end())
	{
		if(*p == prime_candidate) return true;
		if(*p > prime_candidate) return false;
		++p;
	}
	printf("NOT SUPPOSED TO BE HERE, %ld \n",prime_candidate);
	return false;
}

void Problem_27::run()
{
	Prime_list* p = new Prime_list();
	std::vector<int> primes = *(p->get());


	int i = 0;
	int j;

	int a;
	int b = primes[i];
	int count = 0;

	int a_saved = 0;
	int b_saved = 0;
	int count_saved = 0;

	long prime_candidate;

	while(b < 1000) {
		for (a = -999; a < 1000; ++a)
		{
			j = 0;
			count = 0;
			prime_candidate = calc(a,b,j);
			if(prime_candidate > 1)
			{
				while(find_prime(primes, prime_candidate))
				{
					count++;
					j++;
					prime_candidate = calc(a,b,j);
				}
				if(count > count_saved)
				{
/*					printf("a : %d, b : %d, count : %d \n",a,b,count);*/
					a_saved = a;
					b_saved = b;
					count_saved = count;
				}
			}
		}
		i++;
		b = primes[i];
	}
	printf("a : %d, b : %d, count : %d \n",a_saved,b_saved,count_saved);
	printf("%d\n",a_saved*b_saved);
}

