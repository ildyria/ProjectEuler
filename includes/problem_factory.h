#pragma once
#include <iostream>
#include <stdio.h>

#include "problem.h"
#include "../problem/1.h"
#include "../problem/2.h"
#include "../problem/3.h"

class Problem_factory
{
	Problem_factory();
	~Problem_factory();
public:

	static Problem* make(const int& i);
};