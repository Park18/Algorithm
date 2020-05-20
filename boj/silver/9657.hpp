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
        // n 입력
        int n;
        cin >> n;

        // dp 초기화
        int dp[MAX_SIZE] = { };
        dp[1] = 1;
        dp[2] = 0;
        dp[3] = 1;
        dp[4] = 1;

        // dp 계산
        // sk가 돌을 가져왔을 때, 남은 돌이 개수가
        // 1, 3, 4개 남았으면 지는 것이므로
        // dp[index - 1] + dp[index - 3] + dp[index - 4] == 1 이면
        // dp[index]는 sk가 진 것이다.
        for (int index = 5; index <= n; index++)
        {
            if (dp[index - 1] + dp[index - 3] + dp[index - 4] == 3)
                dp[index] = 0;

            else
                dp[index] = 1;
        }

        // 결과 출력
        if (dp[n])
            cout << "SK" << endl;
        else
            cout << "CY" << endl;
	}
} // !namespace silver
} // !namespace boj