/*****************************************************************
 * https://www.acmicpc.net/problem/2579
 * 문제
 * 계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. 
 * <그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 
 * 점수를 얻게 된다.
 *
 * 예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째 계단을 밟아
 * 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다.
 *
 * 계단 오르는 데는 다음과 같은 규칙이 있다.
 *  1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 
 *     이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
 *  2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
 *  3. 마지막 도착 계단은 반드시 밟아야 한다.
 * 따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다.
 * 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 
 * 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.
 * 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는
 *  프로그램을 작성하시오.
 *****************************************************************/
#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

namespace boj
{
namespace silver
{
#define MAX_SIZE 301 // 계단 개수
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