#include "25.h"

void Problem_25::run()
{
	BigInt u1("1");
	BigInt u0("1");
	BigInt temp("");

	u_int term_num = 2;

	while(u1.digits.size() < 1000) {
		temp = u1;
	    u1 = u1 + u0;
	    u0 = temp;
	    term_num++;
	}

	for (auto it = u1.digits.rbegin(); it != u1.digits.rend(); ++it)
	{
		// printf("%d", *it);		/* code */
	}
	// printf("\n");		/* code */
	printf("%d\n", term_num);
}
