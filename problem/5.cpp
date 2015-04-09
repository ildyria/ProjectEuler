#include "5.h"

std::vector<int> Problem_5::dividors(int n)
{
	std::vector<int> res = std::vector<int>(n+1,0);
	while(n > 1 && n % 2 == 0)
	{
		res[2]++;
		n /= 2;
	} 

	int divide_by = 3;
	while(n > 1)
	{
		if(n % divide_by == 0)
		{
			res[divide_by]++;
			n /= divide_by;
		}
		else
		{
			divide_by += 2;
		}
	}

	return res;
}

int Problem_5::pow(int n, int p)
{
	int power = 1;
	for (int i = 0; i < p; ++i)
	{
		power *= n;
	}
	return power;
}

void Problem_5::run()
{
	int n = 20;
	std::vector<int> divider = std::vector<int>(n+1,0);
	std::vector<int> divider_temp;
	for (int i = n; i > 1; --i)
	{
		divider_temp = dividors(i);
		auto iter = divider_temp.begin();
		auto iter_d = divider.begin();
		while(iter != divider_temp.end())
		{
			(*iter_d) = (*iter > *iter_d) ? *iter : *iter_d;
			++iter;
			++iter_d;
		}
	}

	int product = 1;
	for (int i = n; i > 1; --i)
	{
		product *= pow(i,divider[i]);
	}

	printf("%d\n", product);
}