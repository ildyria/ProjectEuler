#pragma once
#include <algorithm>    // std::sort
#include <list>
#include <vector>
#include "../includes/problem.h"

class Problem_24 : public Problem
{
	std::vector<long> power_ten;

std::list<long> generate(const std::list<long>& v);

public:
	Problem_24();
	~Problem_24() {};
	void run();
};