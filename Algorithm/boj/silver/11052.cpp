/**
 * @date 20.05.29
 * @ BOJ 11052
 * @url https://www.acmicpc.net/problem/11052
 */
#include <iostream>
#include <algorithm>

using namespace std;

namespace boj
{
namespace silver
{
    void solution()
    {
        // �Է�
        int N = 0;
        cin >> N;

        int* p = new int[N + 1];
        for (int i = 1; i <= N; i++)
            cin >> p[i];

        // dp �ʱ�ȭ
        int* dp = new int[N + 1];
        dp[1] = p[1];

        // dp ���
        for (int n = 2; n <= N; n++)
        {
            dp[n] = p[n];

            for (int i = 1; i <= n - 1; i++)
                dp[n] = max(dp[n - i] + p[i], dp[n]);
        }

        // ��� ���
        cout << dp[N] << endl;

        delete[] p;
        delete[] dp;
    }
} // !namespace silver
} // !namespace boj