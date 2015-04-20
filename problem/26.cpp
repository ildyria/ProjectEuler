#include "26.h"

int divide(int dividande,int diviseur,std::list<u_short>& res)
{
	u_short quotient = dividande/diviseur;
	u_short reste = dividande % diviseur;
/*	printf("%d -- %d\n", quotient, reste);*/

	if(reste == 0) return 0;

	if(quotient == 0)
	{
		res.push_front(reste*10);
		return divide(dividande*10,diviseur,res);
	}

	res.push_back(reste);
	u_short occurence = 0;
	u_short length = 0;
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		if(reste == *it)
		{
			occurence++;
		}
		if(occurence == 2) return (length - 1);
		length++
;	}

	return divide((dividande - quotient*diviseur)*10,diviseur,res);
}

void Problem_26::run()
{
/*	std::list<u_short> l2 = std::list<u_short>();
	divide(1,983,l2);
	exit(1);
*/	int found = 2;
	int length = 0;
	int temp_length;
	for (int d = 3; d < 1000; ++d)
	{
		std::list<u_short> l2 = std::list<u_short>();
		temp_length = divide(1,d,l2);
		if(temp_length > length)
		{
			found = d;
			length = temp_length;
		}
	}

	printf("num : %d\n", found);
	printf("length : %d\n", length);
}

