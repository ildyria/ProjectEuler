#include "29.h"

void Problem_29::run()
{
	std::list<BigInt> l = std::list<BigInt>();
	BigInt num = BigInt("2");
	BigInt res = BigInt();
	for (int a = 2; a <= 100; ++a)
	{
		res = num;
		for (int b = 2; b <= 100; ++b)
		{
			res *= num;
			res.compact();
			l.push_back(res);
		}
		num += BigInt("1");
	}

	l.sort();
	l.unique();
	// for(auto ul = l.begin(); ul != l.end(); ++ul)
	// {
	// 	for (auto it = (*ul).digits.rbegin(); it != (*ul).digits.rend(); ++it)
	// 	{
	// 		printf("%d", *it);		/* code */
	// 	}
	// 	printf("\n");
	// }
	printf("%ld\n", l.size());
}

