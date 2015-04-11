#include "15.h"

void Problem_15::run()
{	
/*	int n = 4;*/
	int n = 20;
	std::vector<std::vector<u_long>> lattice = std::vector<std::vector<u_long>>(n+1,std::vector<u_long>(n+1,0));
	for (int i = 0; i < n + 1; ++i)
	{
		lattice[0][i] = 1;
		lattice[i][0] = 1;
	}

/*	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			printf("%3ld", lattice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
*/

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			lattice[i][j]=lattice[i-1][j]+lattice[i][j-1];
		}
	}

	printf("%ld\n", lattice[n][n]);
}

