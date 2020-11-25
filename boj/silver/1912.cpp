/**
 * @date 20.05.27
 * @brief 1912
 * @url https://www.acmicpc.net/problem/1912
 */

#include <iostream>
#include <algorithm>

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief �ٸ� ��� Ǯ��
     * @url https://sihyungyou.github.io/baekjoon-1912/
     */
    void solution_another()
    {
        // �Է�
        int n;
        cin >> n;

        int* num = new int[n];
        for (int index = 0; index < n; index++)
            cin >> num[index];

        // dp �ʱ�ȭ
        int* dp = new int[n];
        dp[0] = num[0];
        int ans = dp[0];

        // dp ���
        for (int index = 1; index < n; index++)
        {
            // dp[i]�� max(���ӵ� ������ ��� ���� ��, ���� ��)
            // ex) 2, 1, -4, 3, 4, -4, 6,  5, -5, 1
            // dp  2, 3, -1, 3, 7,  3, 9, 14,  9, 10
            // ans 2, 3,  3, 3, 7,  7, 9, 14, 14, 14
            dp[index] = max(num[index], dp[index - 1] + num[index]);
            ans = max(ans, dp[index]);
        }

        // �� ���
        cout << ans << endl;

        delete[] dp;
    }

    void test()
    {
        // �Է�
        int n;
        cin >> n;

        int* dp = new int[n];
        for (int index = 0; index < n; index++)
            cin >> dp[index];

        // dp �ʱ�ȭ


        // dp ���
        for (int index = 1; index < n; index++)
        {
            // 5���� �з��� ã��, But Ʋ�� �з��� �־���
            // ex) dp[i] = dp[i-1] + nums[i]
            //   -> "10, -4, 3" �� ��� dp[3]�� 13�� ����
        }

        // �� ���


        delete[] dp;
    }

} // !namespace silver
} // !namespace boj
