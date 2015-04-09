#pragma once
#include <iostream>
#include <stdio.h>

#include "problem.h"
#include "../problem/1.h"
#include "../problem/2.h"

class Problem_factory
{
public:
	Problem_factory();
	~Problem_factory();

	static Problem* make(const int& i){
		printf("problem chosen : %d\n", i);

		switch(i)
		{
			case 1:
				return new Problem_1();
			case 2:
				return new Problem_2();
			default:
				return new Problem();
		}
	};
};