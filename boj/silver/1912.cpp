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
     * @brief 다른 사람 풀이
     * @url https://www.acmicpc.net/problem/1912
     */
    void solution()
    {
        // 입력
        int n;
        cin >> n;

        int* num = new int[n];
        for (int index = 0; index < n; index++)
            cin >> num[index];

        // dp 초기화
        int* dp = new int[n];
        dp[0] = num[0];
        int ans = dp[0];

        // dp 계산
        for (int index = 1; index < n; index++)
        {
            dp[index] = max(num[index], dp[index - 1] + num[index]);
            ans = max(ans, dp[index]);
        }

        // 값 출력
        cout << ans << endl;

        delete[] dp;
    }

    void test()
    {
        // 입력
        int n;
        cin >> n;

        int* dp = new int[n];
        for (int index = 0; index < n; index++)
            cin >> dp[index];

        // dp 초기화


        // dp 계산
        for (int index = 1; index < n; index++)
        {

        }

        // 값 출력


        delete[] dp;
    }

} // !namespace silver
} // !namespace boj

//int main()
//{
//    // 입력
//    int n;
//    cin >> n;
//
//    int* num = new int[n];
//    for (int index = 0; index < n; index++)
//        cin >> num[index];
//
//    // dp 초기화
//    int* dp = new int[n];
//    dp[0] = num[0];
//    int ans = dp[0];
//
//    // dp 계산
//    for (int index = 1; index < n; index++)
//    {
//        dp[index] = max(num[index], dp[index - 1] + num[index]);
//        ans = max(ans, dp[index]);
//    }
//
//    // 값 출력
//    cout << ans << endl;
//
//    delete[] dp;
//}