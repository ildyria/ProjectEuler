#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
//using namespace std;

struct BigInt
{
	std::vector<int> digits;

	BigInt(std::string str="0");

	BigInt & operator+=(const BigInt & bi);
	BigInt & operator-=(const BigInt & bi);
	BigInt & operator*=(const BigInt & bi);
	BigInt & operator*=(int n);
	BigInt & operator<<=(int n);

	BigInt operator+(const BigInt & bi) const;
	BigInt operator-(const BigInt & bi) const;
	BigInt operator*(const BigInt & bi) const;
	BigInt operator*(int n) const;
	BigInt operator<<(int n) const;
};

typedef const BigInt & BICR;
typedef BigInt & BIR;

struct Ascii2Int { int operator()(int c) {return c-'0';} };

struct Add { int operator()(int a, int b) {return a+b;} };

struct Mul
{
	int k;

	Mul(){}
	Mul(int n):k(n){}

	int operator()(int a) {return a*k;}
};

struct Carry
{
	int & carry;

	Carry(int & c):carry(c){}

	int operator()(int n)
	{
		n+=carry; carry=n/10; n%=10;
		return n;
	}
};

template <class BaseOp>
struct OpWithCarry : public BaseOp, public Carry
{
	OpWithCarry(int & c):Carry(c){}

	int operator()(int a) { return Carry::operator()(BaseOp::operator()(a)); }
	int operator()(int a, int b) { return Carry::operator()(BaseOp::operator()(a,b)); }
};

struct SubWithBorrow
{
	int & borrow;

	SubWithBorrow(int & b):borrow(b){}

	int operator()(int a, int b)
	{
		int n=b-a-borrow;
		borrow=0;
		while (n<0) {n+=10; borrow++;}
		return n;
	}
};

struct Borrow
{
	int & borrow;

	Borrow(int & b):borrow(b){}

	int operator()(int n)
	{
		n-=borrow; borrow=0;
		while (n<0) {n+=10; borrow++;}
		return n;
	}
};


/*
void test(string s1, string s2)
{
	BigInt n1(s1);
	BigInt n2(s2);
	BigInt rs, rk;

	int start_s, stop_s, start_k, stop_k;

	start_s=clock();
	rs=n1*n2;
	stop_s=clock();

	start_k=clock();
	rk=karatsuba(n1,n2);
	stop_k=clock();

	cout << rs << endl;
	cout << rk << endl;
	cout << "standard time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	cout << "karatsuba time: " << (stop_k-start_k)/double(CLOCKS_PER_SEC)*1000 << endl;
}*/
/*
int main()
{
	test(
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
	cout << "\nhit enter to continue..." << endl;
	cin.get();

	test(
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
	cout << "\nhit enter to continue..." << endl;
	cin.get();

	test(
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
	cout << "\nhit enter to continue..." << endl;
	cin.get();

	test(
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
	cout << "\nhit enter to continue..." << endl;
	cin.get();

	test(
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
	"123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
	"987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
	cout << "\nhit enter to continue..." << endl;
	cin.get();

	return 0;
}*/