/**
 * @date 20.11.10
 * @url https://www.acmicpc.net/problem/11047
 * @result ¼º°ø
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;
vector<int> coin_group;
int count = 0;

void input_data()
{
	cin >> N >> K;
	for (int loop = 0; loop < N; loop++)
	{
		int coin;
		cin >> coin;
		coin_group.push_back(coin);
	}
}

void solved()
{
	sort(coin_group.begin(), coin_group.end(), greater<int>());
	
	for (int index = 0; index < N; index++)
	{
		for (; K - coin_group[index] >= 0;)
		{
			::count++;
			K -= coin_group[index];
		}
	}
}

int main()
{
	input_data();

	solved();

	cout << ::count << endl;
}