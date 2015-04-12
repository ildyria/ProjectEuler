/* return the list of the 10 000st prime numbers... */

#pragma once
#include <vector>
#include <math.h>
#include "../includes/problem.h"

class Prime_list : public Problem
{
	std::vector<int> primes;
	bool is_prime(u_long n);
public:
	Prime_list();
	~Prime_list() {};
	void run();
	std::vector<int>* get();

	int pow(int n, int p);
	std::vector<int> prime_factorisation(int n);
	std::vector<int> divisor_list(const std::vector<int>& primeMultiplicity);
};
