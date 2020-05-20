/*****************************************************************
 * https://www.acmicpc.net/problem/10844
 * 문제
 * 45656이란 수를 보자.
 * 이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
 * 세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
 * N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오.
 * (0으로 시작하는 수는 없다.)
 *****************************************************************/

#pragma once
#include <iostream>

using namespace std;

namespace my
{
    int test_main_1()
    {
        int n;
        cin >> n;

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

#define N_MAX_SIZE 101  // N의 최대 입력값
#define NUM_MAX_SIZE 10 // 0~9
    int test_main_2()
    {
        int dp[N_MAX_SIZE][NUM_MAX_SIZE] = { 0 };
        int n;
        cin >> n;

        // dp 초기화
        for (int num_index = 0; num_index < NUM_MAX_SIZE; num_index++)
            dp[1][num_index] = 1;

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

        int sum = 0;
        for (int index = 1; index <= NUM_MAX_SIZE; index++)
            sum = (sum + dp[n][index]) % 1000000000;

        cout << sum << endl;

        return 0;
    }
}