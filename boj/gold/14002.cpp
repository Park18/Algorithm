/**
 * @date 20.05.31
 * @brief BOJ 14002
 * @url https://www.acmicpc.net/problem/14002
 */

#include <iostream>
#include <algorithm>

int* A;
int* dp;
int* before_pos;

using namespace std;
void print_arr(int index)
{
	if (before_pos[index] != -1)
		print_arr(before_pos[index]);

	cout << A[index] << " ";
}

int main()
{
	// 입력
	int n;
	cin >> n;

	A = new int[n];
	for (int index = 0; index < n; index++)
		cin >> A[index];

	// 초기화
	dp = new int[n]; // i번째의 최대 길이
	before_pos = new int[n]; // i번째 전의 dp 위치
	before_pos[0] = -1;

	// dp 계산
	// 위치 계산
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1; // 최소 자기 혼자인 길이
		before_pos[i] = -1;

		for (int j = 0; j < i; j++)
		{
			// dp 계산
			// A[0 ~ i-1] < A[i] 이고
			// dp[i] < dp[0 ~ i-1] 이면
			if (A[j] < A[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1; // dp 값
				before_pos[i] = j; // A[i] 전에 오는 값의 위치 = j
			}

		}
	}

	// 결과 출력
	cout << *max_element(dp, dp+n) << endl;
	cout<< find(dp, dp + n, *max_element(dp, dp + n)) - dp <<endl;
	print_arr(find(dp, dp + n, *max_element(dp, dp + n)) - dp);
}