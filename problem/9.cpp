#include "9.h"

void Problem_9::run()
{
	int a,b,c;
	for (a = 1; a < 1000; ++a)
	{
		for (b = a+1; b < 1000; ++b)
		{
			c = 1000 - (a + b);
			if(c <= b) break;
			if(a*a + b*b == c*c) break;
		}
		if(a*a + b*b == c*c) break;
	}
	printf("a^2 + b^2 = c^2\n");
	printf("%d^2 + %d^2 = %d^2\n",a,b,c);
	printf("%d + %d = %d\n",a*a,b*b,c*c);
	printf("%d\n", a*b*c);
}