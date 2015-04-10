#pragma once
#include "../includes/problem.h"
#include <math.h>

class Problem_10 : public Problem
{
	bool is_prime(int n);
public:
	Problem_10():Problem() {};
	~Problem_10() {};
	void run();
};
