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

	inline void set_max(int& a, const int& b)		{ if(a < b) a = b; }
	inline void set_max(u_int& a, const u_int& b)	{ if(a < b) a = b; }

	inline void set_max(short& a, const short& b)	{ if(a < b) a = b; }

	inline void set_max(long& a, const long& b)		{ if(a < b) a = b; }
	inline void set_max(u_long& a, const u_long& b)	{ if(a < b) a = b; }

};