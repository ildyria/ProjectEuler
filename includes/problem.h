#pragma once
#include <iostream>
#include <stdio.h>

class Problem
{
public:
	Problem(){};
	virtual ~Problem(){};
	virtual void run()
	{
		printf("not solved yet\n");
	}
};