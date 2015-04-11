#pragma once
#include <vector>
#include "../includes/problem.h"

class Problem_14 : public Problem
{
	std::vector<int> collatz_length;
	std::vector<u_long> flight;

	int collatz(u_long& num, int& count);
	void fly(u_long n);

public:
	Problem_14();
	~Problem_14() {};
	void run();
};

