#pragma once
#include <iostream>

using namespace std;

void my_turn(int* n)
{
	if ((*n - 3) % 2 == 0)
		*n -= 3;

	if ((*n - 4) % 2 == 0)
		*n -= 4;
}

int main()
{
	int n;
	cin >> n;

	int turn = 1;

	for (; n > 0;)
	{
		my_turn(&n);
	}

	if (turn % 2)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;
}