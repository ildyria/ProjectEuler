#pragma once
#include <vector>
#include "../includes/problem.h"

class Problem_5 : public Problem
{
	std::vector<int> dividors(int n);
	int pow(int n, int p);
public:
	Problem_5():Problem() {};
	~Problem_5() {};
	void run();
};
