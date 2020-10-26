/**
 * @date 20.10.23
 * @url https://www.acmicpc.net/problem/1644
 * @result ¼º°ø
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 4000000

bool* is_prime;
vector<int> prime_num;
int N;
int count = 0;

void input_data()
{
	cin >> N;

	is_prime = new bool[N + 1];
	memset(is_prime, true, sizeof(bool) * (N + 1));

	for (int num = 2; num < N + 1; num++)
	{
		if (is_prime[num] == true)
		{
			for (int non_prime_num = num * 2; non_prime_num <= N + 1; non_prime_num += num)
			{
				is_prime[non_prime_num] = false;
			}
		}
	}

	for (int num = 2; num < N + 1; num++)
	{
		if (is_prime[num])
			prime_num.push_back(num);
	}
}

void soved()
{
	int start = 0;
	int end = 0;
	int sum = 0;

	while (true)
	{
		if (sum >= N)
		{
			sum -= prime_num[start++];
		}

		else if (end == prime_num.size())
			break;

		else
			sum += prime_num[end++];
		
		if (sum == N) ::count++;
	}
}

int main()
{
	input_data();

	soved();

	cout << ::count << endl;
}