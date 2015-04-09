#pragma once
#include "../includes/problem.h"

class Problem_4 : public Problem
{
	bool is_palindrome(int n);
public:
	Problem_4():Problem() {};
	~Problem_4() {};
	void run();
};
