/**
 * @date 20.05.24
 * @brief BOJ 1932
 * @url https://www.acmicpc.net/problem/1932
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 501

using namespace std;
namespace boj
{
namespace silver
{
	/**
	 * @brief DP를 이용한 문제풀이, 스터디 후에 풀음
	 */
	void solution()
	{
		int n;
		cin >> n;

		int** dp = new int* [n];
		for (int n_index = 0; n_index < n; n_index++)
		{
			dp[n_index] = new int[n_index + 1];

			for (int num_index = 0; num_index <= n_index; num_index++)
				cin >> dp[n_index][num_index];
		}

		int max = dp[0][0];
		for (int n_index = 1; n_index < n; n_index++)
		{
			for (int num_index = 0; num_index <= n_index; num_index++)
			{
				if (num_index == 0)
					dp[n_index][num_index] += dp[n_index - 1][num_index];

				else if (num_index == n_index)
					dp[n_index][num_index] += dp[n_index - 1][num_index - 1];

				else
					dp[n_index][num_index] =
					std::max(dp[n_index - 1][num_index - 1], dp[n_index - 1][num_index]) + dp[n_index][num_index];

				if (max < dp[n_index][num_index])
					max = dp[n_index][num_index];
			}
		}

		cout << max << endl;
	}
} // !namespace silver
} // !namespace boj