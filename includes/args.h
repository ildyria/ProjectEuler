#pragma once
#include <stdio.h>
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
#include <cstdlib> 

int read_args(int& argc, char const* argv[])
{
	int i = 1;
	// report settings
	if (argc == 2)
	{
		i = strtol(argv[1],0,10) > 1 ? strtol(argv[1],0,10) : 1;
	}
	else
	{
		printf("problem by default\n");
	}

	return i;
}