/**
 * @date 20.11.24
 * @url https://www.acmicpc.net/problem/12865
 * @result ¼º°ø
 * @source https://naivep.tistory.com/71
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 100
#define K_MAX 100000
#define endl '\n';

using namespace std;

int N, K;
int dp[N_MAX + 1][K_MAX + 1];
int w[N_MAX + 1];
int v[N_MAX + 1];

void input_data()
{
	cin >> N >> K;
	for (int index = 1; index <= N; index++)
		cin >> w[index] >> v[index];
}

void solved()
{
	for (int product = 1; product <= N; product++)
	{
		for (int bag = 1; bag <= K; bag++)
		{
			dp[product][bag] = dp[product - 1][bag];

			if (bag - w[product] >= 0)
				dp[product][bag] = max(dp[product][bag], dp[product - 1][bag - w[product]] + v[product]);
		}
	}
}

int main()
{
	input_data();

	solved();

	cout << dp[N][K] << endl;
}