#pragma once
#include "../includes/problem.h"
#include <vector>

class Problem_11 : public Problem
{
	int Product_line(int i, int j, std::vector<std::vector<int>>& v);
	int Product_col(int i, int j, std::vector<std::vector<int>>& v);
	int Product_diag1(int i, int j, std::vector<std::vector<int>>& v);
	int Product_diag2(int i, int j, std::vector<std::vector<int>>& v);

public:
	Problem_11():Problem() {};
	~Problem_11() {};
	void run();
};
