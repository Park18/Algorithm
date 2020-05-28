/**
 * @date 20.05.22
 * @brief BOJ 9095
 * @url https://www.acmicpc.net/problem/9095
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 12

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief DP를 이용한 문제풀이
     */
    void soultion()
    {
        // 입력
        int n;
        cin >> n;

        int num[MAX_SIZE] = { 0 };
        for (int index = 1; index <= n; index++)
            cin >> num[index];

        // dp 초기화
        int dp[MAX_SIZE] = { 0 };
        dp[1] = 1; // (1)
        dp[2] = 2; // (1,1), (2)
        dp[3] = 4; // (1,1,1), (1,2), (2,1), (3)

        // dp 계산
        for (int i = 4; i <= *max_element(num, num+MAX_SIZE); i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        
        // 출력
        for (int index = 1; index <= n; index++)
            cout << dp[num[index]] << endl;
    }
} // !namespace silver
} // !namespace boj