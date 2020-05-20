/*****************************************************************
 * https://www.acmicpc.net/problem/10844
 * ����
 * 45656�̶� ���� ����.
 * �� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.
 * �����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.
 * N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 * (0���� �����ϴ� ���� ����.)
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

#define N_MAX_SIZE 101  // N�� �ִ� �Է°�
#define NUM_MAX_SIZE 10 // 0~9
    int test_main_2()
    {
        int dp[N_MAX_SIZE][NUM_MAX_SIZE] = { 0 };
        int n;
        cin >> n;

        // dp �ʱ�ȭ
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