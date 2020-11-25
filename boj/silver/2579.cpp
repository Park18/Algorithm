/**
 * @date 20.05.19
 * @brief BOJ 2579
 * @url https://www.acmicpc.net/problem/2579
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 301 // 계단 개수

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief DP를 이용한 풀이, 스터디 후에 풀음
     */
    int solution()
    {
        // 계단 수 입력
        int n; // 계단의 개수
        cin >> n;

        // 계단 별 점수 입력
        int score[MAX_SIZE] = { 0 }; // 계단 점수
        for (int step = 1; step <= n; step++)
            cin >> score[step];

        // dp 초기화
        int dp[MAX_SIZE] = { 0 }; // dp
        dp[1] = score[1];
        dp[2] = score[1] + score[2];
        dp[3] = max(score[1] + score[3], score[2] + score[3]);

        // dp 계산
        for (int step = 4; step <= n; step++)
            dp[step] = max(dp[step - 3] + score[step - 1] + score[step],
                dp[step - 2] + score[step]);

        // 결과 출력
        cout << dp[n] << endl;
        return 0;
    }
} // !namespace silver
} // !namespace boj