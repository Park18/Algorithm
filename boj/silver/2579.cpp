/**
 * @date 20.05.19
 * @brief BOJ 2579
 * @url https://www.acmicpc.net/problem/2579
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 301 // ��� ����

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief DP�� �̿��� Ǯ��, ���͵� �Ŀ� Ǯ��
     */
    int solution()
    {
        // ��� �� �Է�
        int n; // ����� ����
        cin >> n;

        // ��� �� ���� �Է�
        int score[MAX_SIZE] = { 0 }; // ��� ����
        for (int step = 1; step <= n; step++)
            cin >> score[step];

        // dp �ʱ�ȭ
        int dp[MAX_SIZE] = { 0 }; // dp
        dp[1] = score[1];
        dp[2] = score[1] + score[2];
        dp[3] = max(score[1] + score[3], score[2] + score[3]);

        // dp ���
        for (int step = 4; step <= n; step++)
            dp[step] = max(dp[step - 3] + score[step - 1] + score[step],
                dp[step - 2] + score[step]);

        // ��� ���
        cout << dp[n] << endl;
        return 0;
    }
} // !namespace silver
} // !namespace boj