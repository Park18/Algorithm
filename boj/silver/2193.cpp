/**
 * @date 20.05.25
 * @brief BOJ 2193
 * @url https://www.acmicpc.net/problem/2193
 */

#include <iostream>

using namespace std;
namespace boj
{
namespace
{
    /**
     * @brief DP를 이용한 문제풀이
     */
    void solution()
    {
        int n;
        cin >> n;

        unsigned long long* dp = new unsigned long long[n + 1];
        dp[1] = 1;
        dp[2] = 1;

        for (int index = 3; index <= n; index++)
            dp[index] = dp[index - 1] + dp[index - 2];

        cout << dp[n];
        delete[] dp;
    }
}
}