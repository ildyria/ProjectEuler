#include "20.h"

void Problem_20::run()
{
	Prime_list* p = new Prime_list();
	std::vector<int> primes = *(p->get());

	int num_prime = 0;
	while(primes[num_prime] < 100)++num_prime;

	std::vector<int> res = std::vector<int>(num_prime,0);

	int i, n;
	for(int k = 2; k <= 100; k++)
	{
		i = 0;
		n = k;
		while(n > 1)
		{
			if(n % primes[i] == 0)
			{
				res[i]++;
				n /= primes[i];
			}
			else
			{
				++i;
			}
		}
	}

/*
	for (u_int j = 0; j < res.size(); ++j)
	{
		printf("%d ^ %d\n", primes[j], res[j]);
	}

	printf("----------------\n");
*/
	res[0] -= res[2]; // 2 x 5 = 10 => 0
	res[2] = 0;

	std::vector<u_int> result = std::vector<u_int>(1000000,0);
	result[0]=1;
	int decimal = 0;
	int temp;
	for (int i = res.size()-1; i >= 0; --i)
	{
		for (int power = 1; power <= res[i]; ++power)
		{
			for (int j = decimal; j >= 0; --j)
			{
				result[j] = result[j]*primes[i];
				int c = 0;
				temp = result[j+c];
				while(temp > 0)
				{
					result[j+c] = temp%10;
					result[j+c+1] += temp/10;
					c++;
					temp = result[j+c];
				}
				while(result[decimal + 4] > 0) decimal+=4;
				while(result[decimal + 3] > 0) decimal+=3;
				while(result[decimal + 2] > 0) decimal+=2;
				while(result[decimal + 1] > 0) decimal++;
			}
		}

/*
		for (int i = decimal; i >= 0; --i)
		{
			printf("%d", result[i]);
		}
		printf("\n");
*/
	}
	u_long sum = 0;
	for (int i = decimal; i >= 0; --i)
	{
		sum += result[i];
	}
	printf("%ld\n", sum);
}

