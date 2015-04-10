#pragma once
#include <vector>
#include <math.h>
#include "../includes/problem.h"

class Problem_7 : public Problem
{
	bool is_prime(u_long n);
public:
	Problem_7():Problem() {};
	~Problem_7() {};
	void run();
};
