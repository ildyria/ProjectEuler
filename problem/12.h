#pragma once
#include "../includes/problem.h"
#include "../tools/prime_list.h"

class Problem_12 : public Problem
{
	int count(int n, Prime_list* p);
public:
	Problem_12():Problem() {};
	~Problem_12() {};
	void run();
};

