#include "4.h"
bool Problem_4::is_palindrome(int n)
{
	std::string s = std::to_string(n);
	bool is = true;
	int l = s.length();
	int it_e = l - 1;
	for (int it_b = 0; it_b < l/2; ++it_b)
	{
		if(s[it_b] != s[it_e])
		{
			is = false;
		}
		it_e --;
	}
	return is;
}

void Problem_4::run()
{
/*	printf("%d\n", is_palindrome(1001));
	printf("%d\n", is_palindrome(10101));
	printf("%d\n", is_palindrome(123456));
*/	
	int n;
	int max_n = 0;
	for (int i = 100; i < 1000; ++i)
	{
		for (int j = i; j < 1000; ++j)
		{
			n = i*j;
			if(is_palindrome(n))
			{
/*				printf("%d * %d = %d\n", i,j,n);*/
				if(max_n < n) max_n = n;
			}
		}
	}

	printf("%d\n",max_n);

}