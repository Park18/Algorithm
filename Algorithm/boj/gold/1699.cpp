/**
 * @date 20.06.01
 * @ BOJ 1699
 * @url https://www.acmicpc.net/problem/1699
 */

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    // 입력
    int n;
    cin >> n;

    // dp 초기화
    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    // dp 계산
    for (int i = 4; i <= n; i++)
    {
        dp[i] = 100000;

        for (int a = 1; a * a <= i; a++)
        {
            dp[i] = min(dp[i - (a * a)] + 1, dp[i]);
        }
    }

    // 결과 출력
    cout << dp[n] << endl;

    delete[] dp;
}