#include "19.h"

bool is_leap(u_int	year)
{
	if(year % 4 != 0) return false;
	if(year % 400 == 0) return true;
	if(year % 100 == 0) return false;
	return true;
}
void Problem_19::run()
{
	std::vector<short> months = {31,28,31,30,31,30,31,31,30,31,30,31};

	u_int day = 1;
	u_int year = 1900;

	// 1900
	for (int i = 0; i < 12; ++i)
	{
		day += months[i];
		if(i == 1 && is_leap(year)) day++;
		day %= 7;
	}
	year ++;


	u_int count = 0;
	while(year <= 2000)
	{
/*		printf("%d -- %s\n",year,(is_leap(year)?"yes":"no"));*/
		for (int i = 0; i < 12; ++i)
		{
			day += months[i];
			if(i == 1 && is_leap(year)) day++;
			day %= 7;
			if(day == 0) count ++;
		}
		year++;
	}

	printf("%d\n", count);
}

