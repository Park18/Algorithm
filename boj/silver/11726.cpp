/**
 * @date 20.05.06
 * @brief BOJ 11726
 * @url https://www.acmicpc.net/problem/11726
 */

#include <iostream>

using namespace std;

namespace boj
{
namespace silver
{
	/**
	 * @brief DP를 이용한 문제풀이
	 */
	void solution()
	{
		int count[1001];	// 1<=n<=1000
		count[1] = 1;		// 초기값1
		count[2] = 2;		// 초기값2

		int n;
		cin.tie(nullptr);
		cin >> n;

		// DP 계산
		// 그냥 피보나치로만 계산하면 값이 매우 커지기 때문에
		// 10007을 값으로 초기화한다.
		for (int index = 3; index <= n; index++)
			count[index] = (count[index - 1] + count[index - 2]) % 10007;

		cout << count[n] << endl;	
	}

	/**
	 * @brief 재귀를 이용한 문제풀이, 시간초과
	 */
	int fibo(int n)
	{
		if (n == 0 || n == 1) return 1;
		return fibo(n - 1) + fibo(n - 2);
	}

	void test(int argc, char* argv[])
	{
		int n;
		cin >> n;

		int count = fibo(n);
		cout << count % 10007 << endl;
	}
} // !namespace silver
} // !namespace boj