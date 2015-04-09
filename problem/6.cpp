#include "6.h"

void Problem_6::run()
{

	// S1= sum 1 .. n  = n ( n + 1) / 2
	// S2 = sum 1^2 .. n^2 = n (n+1) (2n +1) / 6

	// S1^2 - S2 = n (n + 1) n (n + 1) 3 / 2 / 2 / 3 - n (n+1) (2n+1) / 6
	// = n (n+1) / 6 (n (n+1) 3 / 2 - (2n+1)

	u_long n = 100;

	u_long res = n*(n+1)*(n*(n+1)*3/2 - (2*n+1))/6;
	printf("%ld\n", res);
}