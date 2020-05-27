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
     * @url https://www.acmicpc.net/problem/1912
     */
    void solution()
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

        }

        // �� ���


        delete[] dp;
    }

} // !namespace silver
} // !namespace boj

//int main()
//{
//    // �Է�
//    int n;
//    cin >> n;
//
//    int* num = new int[n];
//    for (int index = 0; index < n; index++)
//        cin >> num[index];
//
//    // dp �ʱ�ȭ
//    int* dp = new int[n];
//    dp[0] = num[0];
//    int ans = dp[0];
//
//    // dp ���
//    for (int index = 1; index < n; index++)
//    {
//        dp[index] = max(num[index], dp[index - 1] + num[index]);
//        ans = max(ans, dp[index]);
//    }
//
//    // �� ���
//    cout << ans << endl;
//
//    delete[] dp;
//}