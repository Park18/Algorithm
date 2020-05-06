#pragma once
#include <iostream>

using namespace std;

namespace my
{
int fibo(int n)
{
	if (n == 0 || n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}

void test_main_1(int argc, char* argv[])
{
	int n;
	cin >> n;

	int count = fibo(n);
	cout << count % 10007 << endl;
}

void test_main_2()
{
	int count[1001];
	count[1] = 1;
	count[2] = 2;

	int n;
	cin.tie(nullptr);
	cin >> n;

	for (int index = 3; index <= n; index++)
		count[index] = (count[index - 1] + count[index - 2]) % 10007;

	cout << count[n] << endl;
	
}

}