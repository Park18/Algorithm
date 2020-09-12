/**
 * @date 20.06.03
 * @brief BOJ 11054
 * @url https://www.acmicpc.net/problem/11054
 */

#include <iostream>
#include <algorithm>

using namespace std;

int* A;
int* dp_up;
int* dp_down;
int* dp;

/**
 * @brief 올라가는 형식의 dp계산하는 메소드
 * @param 배열의 크기
 */
void get_dp_up(int size)
{
    for (int i = 0; i < size; i++)
    {
        dp_up[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i] && dp_up[i] < dp_up[j] + 1)
                dp_up[i] = dp_up[j] + 1;
        }
    }
}

/**
 * @brief 내려가는 형식의 dp계산하는 메소드
 * @param 배열의 크기
 */
void get_dp_down(int size)
{
    for (int i = size - 1; i > -1; i--)
    {
        dp_down[i] = 1;

        for (int j = i; j < size; j++)
        {
            if (A[i] > A[j] && dp_down[i] < dp_down[j] + 1 )
            {
                dp_down[i] = dp_down[j] + 1;
            }
        }
    }
}

int main()
{
    // 입력
    int n;
    cin >> n;

    A = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> A[i];

    //dp 초기화
    dp_up = new int[n];
    dp_down = new int[n];
    dp = new int[n];

    // dp 계산
    get_dp_up(n);
    get_dp_down(n);

    for (int i = 0; i < n; i++)
        dp[i] = dp_up[i] + dp_down[i] - 1;

    // 결과 출력
    cout << *max_element(dp, dp + n) << endl;
}
