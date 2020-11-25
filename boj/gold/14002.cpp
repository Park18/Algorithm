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
	// �Է�
	int n;
	cin >> n;

	A = new int[n];
	for (int index = 0; index < n; index++)
		cin >> A[index];

	// �ʱ�ȭ
	dp = new int[n]; // i��°�� �ִ� ����
	before_pos = new int[n]; // i��° ���� dp ��ġ
	before_pos[0] = -1;

	// dp ���
	// ��ġ ���
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1; // �ּ� �ڱ� ȥ���� ����
		before_pos[i] = -1;

		for (int j = 0; j < i; j++)
		{
			// dp ���
			// A[0 ~ i-1] < A[i] �̰�
			// dp[i] < dp[0 ~ i-1] �̸�
			if (A[j] < A[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1; // dp ��
				before_pos[i] = j; // A[i] ���� ���� ���� ��ġ = j
			}

		}
	}

	// ��� ���
	cout << *max_element(dp, dp+n) << endl;
	cout<< find(dp, dp + n, *max_element(dp, dp + n)) - dp <<endl;
	print_arr(find(dp, dp + n, *max_element(dp, dp + n)) - dp);
}