#include "14.h"

Problem_14::Problem_14():Problem(), collatz_length(std::vector<int>(1000000,0)), flight(std::vector<u_long>(1000000,0)) {
	int i = 1;
	int count = 0;
	// init table to speed the search
	while(i < 1000000)
	{
		collatz_length[i] = count;
		i*=2;
		count++;
	}
}

int Problem_14::collatz(u_long& num, int& count)
{
	flight[count] = num;
	if(num < 1000000)
	{
		if(collatz_length[num] != 0)
			return collatz_length[num];
	}

	if(num % 2 == 1)
	{
		num = num * 3 + 1;
		count ++;
	}
	else
	{
		num /= 2;
		count ++;
	}
	return 0;
}

void Problem_14::fly(u_long n)
{
	int count = 0;
	int fast_count = 0;
	while(n != 1 && fast_count == 0)
	{
/*		printf("%ld -- %d\n", n ,count);*/
		fast_count = collatz(n,count);
	}

	u_long num = 0;
	for(int i = count - 1; i >= 0; --i )
	{
		fast_count++;
		num = flight[i];
		if(num < 1000000)
		{
			collatz_length[num]=fast_count;
		}
	}
}

void Problem_14::run()
{
	for(u_long i = 1; i < 1000000 ; i ++)
	{
/*		printf("%ld\n", i);*/
		fly(i);
	}

	int max_flight = 0;
	int start = 0;
	for(int i = 1; i < 1000000; i++)
	{
		if(max_flight < collatz_length[i])
		{
			start = i;
			max_flight = collatz_length[i];
		}
	}
	printf("%d\n", start);
}

