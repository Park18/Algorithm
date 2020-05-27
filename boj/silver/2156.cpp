/**
 * @brief 2156
 * @date 20/5/26
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 10000

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief 정적배열을 이용한 문제풀이
     */
    void solution_static()
    {
        int n;
        cin >> n;

        int arr[MAX_SIZE + 1] = { 0 };
        for (int index = 1; index <= n; index++) cin >> arr[index];

        int dp[MAX_SIZE + 1] = { 0 };
        dp[1] = arr[1];
        dp[2] = arr[1] + arr[2];
        dp[3] = max(arr[1] + arr[2], arr[1] + arr[3]);
        dp[3] = max(dp[3], arr[2] + arr[3]);

        for (int i = 4; i <= n; i++)
        {
            dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);

            if (dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
        }

        cout << dp[n] << endl;
    }

    /**
     * 동적 배열을 이용한 문제풀이
     */
    void solution_dinamic()
    {
        // 입력
        int n;
        cin >> n;

        int* arr = new int[n];
        for (int index = 0; index < n; index++) cin >> arr[index];

        // dp 초기화
        int* dp = new int[n];
        dp[0] = arr[0];
        dp[1] = arr[0] + arr[1];
        dp[2] = max(arr[0] + arr[1], arr[0] + arr[2]);
        dp[2] = max(dp[2], arr[1] + arr[2]);

        // dp 계산
        for (int i = 3; i < n; i++)
        {
            dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);

            if (dp[i] < dp[i - 1])dp[i] = dp[i - 1];
        }

        // 결과 출력
        cout << dp[n - 1] << endl;
    }
}
}