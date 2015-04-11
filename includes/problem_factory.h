#pragma once
#include <iostream>
#include <stdio.h>

#include "problem.h"
#include "../problem/1.h"
#include "../problem/10.h"
#include "../problem/11.h"
#include "../problem/12.h"
#include "../problem/13.h"
#include "../problem/14.h"
#include "../problem/15.h"
#include "../problem/16.h"
#include "../problem/2.h"
#include "../problem/3.h"
#include "../problem/4.h"
#include "../problem/5.h"
#include "../problem/6.h"
#include "../problem/7.h"
#include "../problem/8.h"
#include "../problem/9.h"

class Problem_factory
{
	Problem_factory();
	~Problem_factory();
public:
	static Problem* make(const int& i);
};
