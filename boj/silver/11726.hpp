/*****************************************************************
 * https://www.acmicpc.net/problem/11726
 * ����
 * 2xn ũ���� ���簢���� 1x2, 2x1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ�
 * ���α׷��� �ۼ��Ͻÿ�.
 *****************************************************************/

#pragma once
#include <iostream>

using namespace std;

namespace my
{
	/**
	 * @brief �Ǻ���ġ �Լ�
	 * @param int n 
	 */
	int fibo(int n)
	{
		if (n == 0 || n == 1) return 1;
		return fibo(n - 1) + fibo(n - 2);
	}

	/**
	 * @brief �Ǻ���ġ�� �̿��� ����Ǯ��
	 */
	void test_main_1(int argc, char* argv[])
	{
		int n;
		cin >> n;

		int count = fibo(n);
		cout << count % 10007 << endl;
	}

	/**
	 * @brief DP�� �̿��� ����Ǯ��
	 */
	void test_main_2()
	{
		int count[1001];	// 1<=n<=1000
		count[1] = 1;		// �ʱⰪ1
		count[2] = 2;		// �ʱⰪ2

		int n;
		cin.tie(nullptr);
		cin >> n;

		// DP ���
		// �׳� �Ǻ���ġ�θ� ����ϸ� ���� �ſ� Ŀ���� ������
		// 10007�� ������ �ʱ�ȭ�Ѵ�.
		for (int index = 3; index <= n; index++)
			count[index] = (count[index - 1] + count[index - 2]) % 10007;

		cout << count[n] << endl;
	
	}

}