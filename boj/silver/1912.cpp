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
     * @url https://sihyungyou.github.io/baekjoon-1912/
     */
    void solution_another()
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
            // dp[i]는 max(연속된 수열을 모두 더한 값, 현재 값)
            // ex) 2, 1, -4, 3, 4, -4, 6,  5, -5, 1
            // dp  2, 3, -1, 3, 7,  3, 9, 14,  9, 10
            // ans 2, 3,  3, 3, 7,  7, 9, 14, 14, 14
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
            // 5개의 분류를 찾음, But 틀린 분류가 있었음
            // ex) dp[i] = dp[i-1] + nums[i]
            //   -> "10, -4, 3" 의 경우 dp[3]이 13이 나옴
        }

        // 값 출력


        delete[] dp;
    }

} // !namespace silver
} // !namespace boj
