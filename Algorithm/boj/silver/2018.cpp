/**
 * @date 20.10.28
 * @url https://www.acmicpc.net/problem/2018
 * @result ¼º°ø
 */

#include <iostream>

using namespace std;

int N;
int count;

void input_data()
{
	cin >> N;
}

void solved()
{
	int start = 1;
	int end = 1;
	int sum = 0;

	while (true)
	{
		if (sum >= N)
			sum -= start++;

		else if (end == N + 1)
			break;

		else
			sum += end++;

		if (sum == N)
			::count++;
	}
}

int main()
{
	input_data();

	solved();

	cout << ::count << endl;
}