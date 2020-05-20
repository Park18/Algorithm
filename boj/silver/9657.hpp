#pragma once
#include <iostream>

using namespace std;

namespace boj
{
namespace silver
{
#define MAX_SIZE 1001
	void solution()
	{
        // n �Է�
        int n;
        cin >> n;

        // dp �ʱ�ȭ
        int dp[MAX_SIZE] = { };
        dp[1] = 1;
        dp[2] = 0;
        dp[3] = 1;
        dp[4] = 1;

        // dp ���
        // sk�� ���� �������� ��, ���� ���� ������
        // 1, 3, 4�� �������� ���� ���̹Ƿ�
        // dp[index - 1] + dp[index - 3] + dp[index - 4] == 1 �̸�
        // dp[index]�� sk�� �� ���̴�.
        for (int index = 5; index <= n; index++)
        {
            if (dp[index - 1] + dp[index - 3] + dp[index - 4] == 3)
                dp[index] = 0;

            else
                dp[index] = 1;
        }

        // ��� ���
        if (dp[n])
            cout << "SK" << endl;
        else
            cout << "CY" << endl;
	}
} // !namespace silver
} // !namespace boj