/**
 * @date 20.05.18
 * @brief BOJ 1904
 * @url https://www.acmicpc.net/problem/1904
 */

#include <iostream>

#define MAX_SIZE 1000001

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief DP를 이용한 문제풀이
     */
    int solution()
    {
        // dp 초기화
        int dp[MAX_SIZE] = { 0 };
        dp[1] = 1; dp[2] = 2;

        // n 입력
        int n;
        cin >> n;

        // dp 계산
        for (int index = 3; index <= n; index++)
            dp[index] = (dp[index - 2] + dp[index - 1]) % 15746;

        // 결과 출력
        cout << dp[n] << '\n';
    }
} // !namespace silver
} // !namespace boj