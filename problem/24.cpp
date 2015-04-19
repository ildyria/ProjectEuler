#include "24.h"

Problem_24::Problem_24():Problem(), power_ten({1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000}) {}

std::list<long> Problem_24::generate(const std::list<long>& v)
{
	if(v.size() == 1) return v;


	std::list<long> resul = std::list<long>();
	for (auto iter_v = v.begin(); iter_v != v.end(); ++iter_v)
	{
		std::list<long> copy_list = v;
		copy_list.remove(*iter_v);
		std::list<long> g = generate(copy_list);

		long plus = *iter_v * power_ten[v.size() - 1];
		for (auto iter_g = g.begin(); iter_g != g.end(); ++iter_g)
		{
			resul.push_front(*iter_g + plus);
		}
	}

	return resul;
}

void Problem_24::run()
{
	std::list<long> start = {0,1,2,3,4,5,6,7,8,9};
	std::list<long> nums = generate(start);
	nums.sort();
	auto fin = nums.begin();
	for (int i = 0; i < 999999; ++i)
	{
		fin++;
	}
	std::cout << *fin << std::endl;
}

