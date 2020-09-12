/**
 * @date 20.05.30
 * @ BOJ 15990
 * @url https://www.acmicpc.net/problem/15990
 */

#include <iostream>
#include <algorithm>

#define ONE 1
#define TWO 2
#define THR 3

using namespace std;
namespace boj
{
namespace silver
{
    void solution()
    {
        // 입력
        int T;
        cin >> T;

        // dp 초기화
        long long dp[1000001][4] = { 0 };
        dp[1][ONE] = 1;
        dp[2][TWO] = 1;
        dp[3][ONE] = dp[3][TWO] = dp[3][THR] = 1;

        // dp 계산
        for (int i = 4; i <= 1000000; i++)
        {
            dp[i][ONE] = (dp[i - ONE][TWO] + dp[i - ONE][THR]) % 1000000009;
            dp[i][TWO] = (dp[i - TWO][ONE] + dp[i - TWO][THR]) % 1000000009;
            dp[i][THR] = (dp[i - THR][ONE] + dp[i - THR][TWO]) % 1000000009;
        }

        // 결과 출력
        for (int time = 0; time < T; time++)
        {
            int n;
            cin >> n;

            int result = (dp[n][ONE] + dp[n][TWO] + dp[n][THR]) % 1000000009;
            cout << result << endl;
        }
    }

    /**
     * @brief DP를 이용한 문제풀이, 시간초과
     */
    void test()
    {
        // 입력
        int T;
        cin >> T;

        for (int count = 0; count < T; count++)
        {
            int n;
            cin >> n;

            // dp 초기화
            long long dp[1000001][4] = { 0 };
            dp[1][ONE] = 1;
            dp[2][TWO] = 1;
            dp[3][ONE] = dp[3][TWO] = dp[3][THR] = 1;

            // dp 계산
            for (int i = 4; i <= n; i++)
            {
                dp[i][ONE] = (dp[i - ONE][TWO] + dp[i - ONE][THR]) % 1000000009;
                dp[i][TWO] = (dp[i - TWO][ONE] + dp[i - TWO][THR]) % 1000000009;
                dp[i][THR] = (dp[i - THR][ONE] + dp[i - THR][TWO]) % 1000000009;
            }

            // 결과 출력
            long long result = (dp[n][ONE] + dp[n][TWO] + dp[n][THR]) % 1000000009;
            cout << result << endl;
        }
    }
}
}