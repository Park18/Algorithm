/**
 * @date 20.06.02
 * @brief BOJ 13398
 * @url https://www.acmicpc.net/problem/13398
 */

#include <iostream>
#include <algorithm>

using namespace std;
namespace boj
{
namespace gold
{
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
} // !namespace gold
} // !namespace silver