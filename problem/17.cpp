#include "17.h"

void Problem_17::run()
{
	std::vector<std::string> words = std::vector<std::string>(1002,"");
	words[1]="one";
	words[2]="two";
	words[3]="three";
	words[4]="four";
	words[5]="five";
	words[6]="six";
	words[7]="seven";
	words[8]="eight";
	words[9]="nine";
	words[10]="ten";
	words[11]="eleven";
	words[12]="twelve";
	words[13]="thirteen";
	words[14]="fourteen";
	words[15]="fifteen";
	words[16]="sixteen";
	words[17]="seventeen";
	words[18]="eighteen";
	words[19]="nineteen";
	words[20]="twenty";
	words[30]="thirty";
	words[40]="forty";
	words[50]="fifty";
	words[60]="sixty";
	words[70]="seventy";
	words[80]="eighty";
	words[90]="ninety";
	words[100]="hundred";
	words[1000]="thousand";
	words[1001]="and";

	for (int i = 20; i < 100; ++i)
	{
		words[i] = words[i/10*10]+words[i%10];
	}

	for (int i = 101; i < 1000; ++i)
	{
		words[i] = words[i/100] + words[100];
		if (i % 100 > 0)
		 {
		 	words[i] += words[1001] + words[i%100];
		 }
	}
	words[100] = words[1] + words[100];

	words[1000] = words[1] + words[1000];

	u_int sum = 0;
	for (int i = 0; i < 1001; ++i)
	{
/*		std::cout << words[i] << std::endl;*/
		sum += words[i].length();
	}
	printf("%d\n", sum);
}

