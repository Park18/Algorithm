/**
 * @date 20.06.02
 * @brief BOJ 13398
 * @url https://www.acmicpc.net/problem/13398
 */

#include <iostream>
#include <algorithm>

using namespace std;

//-----------------------------------------//
//                  성공
//-----------------------------------------//
int main()
{
	// 입력
	int n;
	cin >> n;

	int* A = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> A[i];

	// dp 초기화
	// 0: i번째가지 삭제하지 않은 경우
	// 1: i번째 중 한 개 삭제한 경우
	int** dp = new int*[n];
	dp[0] = new int[2];
	dp[0][0] = A[0];
	dp[0][1] = A[0]; // 값은 한 개라도 있어야 하기 때문에 첫 번째는 삭제할 수 없다.

	// dp 계산
	for (int i = 1; i < n; i++)
	{
		dp[i] = new int[2];

		for (int is_exist = 0; is_exist <= 1; is_exist++)
		{
			if (is_exist == 0)
			{
				// dp[i-1][삭제x] + A[i]
				// A[i]
				// 중 더 큰 것
				dp[i][0] = max(dp[i - 1][0] + A[i], A[i]);
			}

			else
			{
				// dp[i-1][삭제x]: i-1번째까지 삭제한 것이 없기 때문에 A[i]를 삭제한다.
				// dp[i-1][삭제o] + A[i]: i-1번째 중 삭제한 것이 있기 때문에 A[i]를 더한다.
				dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + A[i]);
			}
		}
	}

	// 결과 출력
	int ans = -1000000000;
	for (int i = 0; i < n; i++)
	{
		for (int is_exist = 0; is_exist <= 1; is_exist++)
			ans = max(ans, dp[i][is_exist]);	
	}

	cout << ans << endl;
}

//-----------------------------------------//
//                  실패
//-----------------------------------------//

/**
	* @brief 배열[시작점] 이후 나오는 첫번째 음수 인데스 반환하는 메소드
	* @param arr 배열
	* @param size 배열의 크기
	* @param start_pos 시작점
	* @return 배열[시작점] 이후 나오는 첫번째 음수의 인덱스
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
	* @brief ans 결과를 구하는 메소드
	* @param arr 배열
	* @param size 배열 크기
	* @param exception_index 예외 인덱스
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