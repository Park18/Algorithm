#include <iostream>
#include <algorithm>

#define MAX_SIZE 501

using namespace std;
int main()
{
	int n;
	cin >> n;

	int** num = new int* [n];
	for (int n_index = 1; n_index <= n; n_index++)
	{
		num[n_index] = new int[n_index];

		for (int num_index = 0; num_index < n_index; num_index++)
			cin >> num[n_index][num_index];
	}

	int* dp = new int[n];
	dp[1] = num[1][0];
	dp[2] = max(num[2][0], num[2][1]);

	for (int n_index = 3; n_index <= n; n_index++)
	{


		dp[n_index] = dp[n_index - 2];
	}
}