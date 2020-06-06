/**
 * @date 20.06.02
 * @brief BOJ 13398
 * @url https://www.acmicpc.net/problem/13398
 */

#include <iostream>
#include <algorithm>

using namespace std;

//-----------------------------------------//
//                  ����
//-----------------------------------------//
int main()
{
	// �Է�
	int n;
	cin >> n;

	int* A = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> A[i];

	// dp �ʱ�ȭ
	// 0: i��°���� �������� ���� ���
	// 1: i��° �� �� �� ������ ���
	int** dp = new int*[n];
	dp[0] = new int[2];
	dp[0][0] = A[0];
	dp[0][1] = A[0]; // ���� �� ���� �־�� �ϱ� ������ ù ��°�� ������ �� ����.

	// dp ���
	for (int i = 1; i < n; i++)
	{
		dp[i] = new int[2];

		for (int is_exist = 0; is_exist <= 1; is_exist++)
		{
			if (is_exist == 0)
			{
				// dp[i-1][����x] + A[i]
				// A[i]
				// �� �� ū ��
				dp[i][0] = max(dp[i - 1][0] + A[i], A[i]);
			}

			else
			{
				// dp[i-1][����x]: i-1��°���� ������ ���� ���� ������ A[i]�� �����Ѵ�.
				// dp[i-1][����o] + A[i]: i-1��° �� ������ ���� �ֱ� ������ A[i]�� ���Ѵ�.
				dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + A[i]);
			}
		}
	}

	// ��� ���
	int ans = -1000000000;
	for (int i = 0; i < n; i++)
	{
		for (int is_exist = 0; is_exist <= 1; is_exist++)
			ans = max(ans, dp[i][is_exist]);	
	}

	cout << ans << endl;
}

//-----------------------------------------//
//                  ����
//-----------------------------------------//

/**
	* @brief �迭[������] ���� ������ ù��° ���� �ε��� ��ȯ�ϴ� �޼ҵ�
	* @param arr �迭
	* @param size �迭�� ũ��
	* @param start_pos ������
	* @return �迭[������] ���� ������ ù��° ������ �ε���
	*/
template<class Ty> int get_first_min_pos(Ty arr, int size, int start_pos)
{
	for (int index = start_pos; index < size; index++)
	{
		if (arr[index] < 0)
			return index;
	}

	return size + 1;
}

/**
	* @brief ans ����� ���ϴ� �޼ҵ�
	* @param arr �迭
	* @param size �迭 ũ��
	* @param exception_index ���� �ε���
	*/
template<class Ty> Ty get_ans(Ty* arr, int size, int exception_index)
{
	long long* dp = new long long[size];
	long long ans = dp[0] = arr[0];
	for (int index = 0; index < size; index++)
	{
		if (index == exception_index && exception_index != 0)
		{
			dp[index] = dp[index - 1];
			continue;
		}
		
		dp[index] = max(dp[index - 1] + arr[index], arr[index]);
		ans = max(ans, dp[index]);
	}

	delete[] dp;
	return ans;
}

int test()
{
	int time;
	cin >> time;

	long long* nums = new long long[time];
	for (int index = 0; index < time; index ++) cin >> nums[index];

	long long* dp = new long long[time];
	long long ans = dp[0] = nums[0];
	for (int index = 0; index < time; index++)
	{
		dp[index] = max(dp[index - 1] + nums[index], nums[index]);
		ans = max(ans, dp[index]);
	}
		

	if (ans < 0)
	{
		cout << ans << endl;
		return 0;
	}

	for (int exception_index = 0; exception_index < time; exception_index++)
	{
		exception_index = get_first_min_pos(dp, time, exception_index);
		ans = max(ans, get_ans(nums, time, exception_index));
	}

	cout << ans << endl;
}