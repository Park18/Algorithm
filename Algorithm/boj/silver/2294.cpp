#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_COIN 100000

void input_coin(int* coin, int size)
{
	for (int i = 0; i < size; i++)
		cin >> coin[i];
}

void init_dp(int* dp, int size)
{
	dp[0] = 0;

	for (int i = 1; i <= size; i++)
		dp[i] = MAX_COIN + 1;
}

void calc_dp(int* coin, int coin_size, int* dp, int dp_size)
{
	for (int coin_index = 0; coin_index < coin_size; coin_index++)
	{
		for (int dp_index = coin[coin_index]; dp_index <= dp_size; dp_index++)
		{
			dp[dp_index] = min(dp[dp_index], dp[dp_index - coin[coin_index]] + 1);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	int* coin = new int[n];
	input_coin(coin, n);

	int* dp = new int[k + 1];
	init_dp(dp, k);
	calc_dp(coin, n, dp, k);

	if (dp[k] > MAX_COIN)
		cout << -1 << endl;
	else
		cout << dp[k] << endl;
}