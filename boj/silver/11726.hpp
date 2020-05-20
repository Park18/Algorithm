/*****************************************************************
 * https://www.acmicpc.net/problem/11726
 * 문제
 * 2xn 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수를 구하는
 * 프로그램을 작성하시오.
 *****************************************************************/

#pragma once
#include <iostream>

using namespace std;

namespace my
{
	/**
	 * @brief 피보나치 함수
	 * @param int n 
	 */
	int fibo(int n)
	{
		if (n == 0 || n == 1) return 1;
		return fibo(n - 1) + fibo(n - 2);
	}

	/**
	 * @brief 피보나치를 이용한 문제풀이
	 */
	void test_main_1(int argc, char* argv[])
	{
		int n;
		cin >> n;

		int count = fibo(n);
		cout << count % 10007 << endl;
	}

	/**
	 * @brief DP를 이용한 문제풀이
	 */
	void test_main_2()
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

}