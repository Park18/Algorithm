/**
  * @date 20.05.17
  * @brief BOJ 10844
  * @url https://www.acmicpc.net/problem/10844
  */

#pragma once
#include <iostream>

#define N_MAX_SIZE 101  // N의 최대 입력값
#define NUM_MAX_SIZE 10 // 0~9

using namespace std;
namespace boj
{
namespace silver
{
    int solution()
    {
        // n 입력
        int n;
        cin >> n;

        // dp 초기화
        int dp[N_MAX_SIZE][NUM_MAX_SIZE] = { 0 };
        for (int num_index = 0; num_index < NUM_MAX_SIZE; num_index++)
            dp[1][num_index] = 1;

        // dp 계산
        for (int n_index = 2; n_index <= n; n_index++)
            for (int num_index = 0; num_index < NUM_MAX_SIZE; num_index++)
            {
                if (num_index == 0)
                    dp[n_index][num_index] = dp[n_index - 1][1] % 1000000000;

                else if (num_index == 9)
                    dp[n_index][num_index] = dp[n_index - 1][8] % 1000000000;

                else
                    dp[n_index][num_index] = (dp[n_index - 1][num_index - 1] + dp[n_index - 1][num_index + 1]) % 1000000000;
            }

        // 결과 계산
        int sum = 0;
        for (int index = 1; index <= NUM_MAX_SIZE; index++)
            sum = (sum + dp[n][index]) % 1000000000;

        // 결과 출력
        cout << sum << endl;

        return 0;
    }

    int test()
    {
        // n 입력
        int n;
        cin >> n;

        // 경우의 수를 잘못 생각한 알고리즘
        // 첫 번째 경우의 수 9
        // 그 이후는 2개의 경우의 수가 있다고 생각
        // 9는 8로만 갈 수 있으므로 생각
        // 따라서 9*2* ... * 2 - 1을 하면 된다고 생각함
        if (n == 1)
            cout << 9 << endl;
        else
        {
            int solution = 9;
            for (int loop = 1; loop < n; loop++)
                solution *= 2;

            solution -= 1;
            cout << solution << endl;
        }

        return 0;
    }
} // !namespace silver
} // !namespace boj