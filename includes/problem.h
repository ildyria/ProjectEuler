#pragma once

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