#include "18.h"

void Problem_18::run()
{
	std::vector<std::vector<short>> triangle =
	{{75},
	{95,64},
	{17,47,82},
	{18,35,87,10},
	{20,4,82,47,65},
	{19,1,23,75,3,34},
	{88,2,77,73,7,63,67},
	{99,65,4,28,6,16,70,92},
	{41,41,26,56,83,40,80,70,33},
	{41,48,72,33,47,32,37,16,94,29},
	{53,71,44,65,25,43,91,52,97,51,14},
	{70,11,33,28,77,73,17,78,39,68,17,57},
	{91,71,52,38,17,14,91,43,58,50,27,29,48},
	{63,66,4,68,89,53,67,30,73,16,69,87,40,31},
	{04,62,98,27,23,9,70,98,73,93,38,53,60,4,23}};

	u_int num = triangle.size();

	/*
	// first heuristic (chose the highest) : didn't worked, would be too easy...
	int sum = triangle[0][0];
	u_int i = 0;
	u_int j = 0;
	while(i < num-1)
	{
		if(triangle[i+1][j] > triangle[i+1][j+1])
		{
			sum += triangle[i+1][j];
			i++;
		}
		else
		{
			sum += triangle[i+1][j+1];
			i++;
			j++;
		}
	}
	*/

	std::vector<std::vector<u_int>> triangle_sol = std::vector<std::vector<u_int>>(num,std::vector<u_int>(num,0));

	triangle_sol[0][0] = triangle[0][0];
	for (u_int i = 1; i < num; ++i)
	{
		triangle_sol[i][0] = triangle_sol[i-1][0] + triangle[i][0];

		for (u_int j = 1; j < triangle[i].size(); ++j)
		{
			if (triangle_sol[i-1][j-1] > triangle_sol[i-1][j])
			{
				triangle_sol[i][j] = triangle_sol[i-1][j-1] + triangle[i][j];
			}
			else
			{
				triangle_sol[i][j] = triangle_sol[i-1][j] + triangle[i][j];
			}
		}
	}

	u_int max = 0;
	for (u_int i = 0; i < num; ++i)
	{
		set_max(max,triangle_sol[num-1][i]);
	}

	printf("----------------\n");
	printf("%d\n", max);
}

