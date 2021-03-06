/**
 * @date 20.05.16
 * @brief BOJ 1003
 * @url https://www.acmicpc.net/problem/1003
 */

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 41

using namespace std;
namespace boj
{
namespace silver
{
	/**
	 * @brief ,스터디 후에 풀음
	 */
	void solution()
	{

	}

	class N
	{
	public:
		int num_0;
		int num_1;

		N() {};
		N(int num_0, int num_1) :num_0(num_0), num_1(num_1) {};
		N operator+(N& other) { return N(num_0 + other.num_0, num_1 + other.num_1); }
	};
		
	void test_2()
	{
		// 변수 선언
		int t;
		vector<int> size;
		vector<N> dp;

		// 입력
		cin >> t;
		for (int index = 0; index < t; index++)
		{
			int input;
			cin >> input;
			size.push_back(input);
		}

		// dp 초기화
		dp.push_back(N(1, 0));
		dp.push_back(N(0, 1));

		// dp 계산
		for (int index = 2; index <= *max_element(size.begin(), size.end()); index++)
			dp.push_back(dp[index - 1] + dp[index - 2]);

		// 값 출력
		for (int index = 0; index < t; index++)
			cout << dp[index].num_0 << " " << dp[index].num_1 << endl;
	}

	void test_2()
	{
		int t;
		cin >> t;

		int* size = new int[t];
		N* dp = new N[t];
		for (int index = 0; index < t; index++)
			cin >> size[index];

		// dp 초기화
		dp[0] = N(1, 0);
		dp[1] = N(0, 1);

		// dp 계산
		for (int index = 2; index <= *max_element(size, size + t); index++)
			dp[index] = dp[index - 1] + dp[index - 2];

		// 값 출력
		for (int index = 0; index < t; index++)
			cout << dp[size[index]].num_0 << " " << dp[size[index]].num_1 << endl;
	}

	void test_3()
	{
		// 변수 선언
		int count;
		int size[MAX_SIZE];
		N dp[MAX_SIZE];

		// 입력
		cin >> count;
		for (int index = 0; index < count; index++)
			cin >> size[index];

		// dp 초기화
		dp[0] = N(1, 0);
		dp[1] = N(0, 1);

		// dp 계산
		for (int index = 2; index <= *max_element(size, size + count); index++)
			dp[index] = dp[index - 1] + dp[index - 2];

		// 값 출력
		for (int index = 0; index < count; index++)
			cout << dp[size[index]].num_0 << " " << dp[size[index]].num_1 << endl;
	}

	void test_4()
	{
		int t;
		int size[MAX_SIZE];
		int num_0[MAX_SIZE];
		int num_1[MAX_SIZE];

		// 입력
		cin >> t;
		for (int index = 0; index < t; index++)
			cin >> size[index];
		// dp 초기화
		num_0[0] = 1;
		num_1[0] = 0;
		num_0[1] = 0;
		num_1[1] = 1;

		// dp 계산
		for (int index = 2; index <= *max_element(size, size + t); index++)
		{
			num_0[index] = num_0[index - 1] + num_0[index - 2];
			num_1[index] = num_1[index - 1] + num_1[index - 2];
		}

		// 값 출력
		for (int index = 0; index < t; index++)
			cout << num_0[size[index]] << " " << num_1[size[index]] << endl;
	}
} // !namespace silver
} // !namespace boj