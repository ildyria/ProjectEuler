#include "28.h"

void Problem_28::run()
{
	int sum = 0;

	int size = 1001;

	int i;
	while(size > 1) {
		i = size*size;
		sum += i;
		size = (size - 1);
		i -= size;
		sum += i;
		i -= size;
		sum += i;
		i -= size;
		sum += i;
		size = (size - 1);
	}

	sum ++; // missing the middle

	printf("%d\n",sum);
}