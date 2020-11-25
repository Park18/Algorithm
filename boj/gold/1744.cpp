/**
 * @date 20.10.31
 * @url https://www.acmicpc.net/problem/1744
 * @reuslt ¼º°ø
 */

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 10000
#define MIN_VALUE -100000000

using namespace std;

int N;
vector<int> plus_group;
vector<int> minus_group;
int result = 0;

void input_data()
{
	cin >> N;
	for (int index = 1; index <= N; index++)
	{
		int num;
		cin >> num;
		if (num > 0)
			plus_group.push_back(num);
		else
			minus_group.push_back(num);
	}
}

void solved()
{
	sort(plus_group.begin(), plus_group.end(), greater<int>());
	sort(minus_group.begin(), minus_group.end(), less<int>());

	for (int index = 0; index < plus_group.size(); index++)
	{
		if (index == plus_group.size() - 1)
		{
			result += plus_group[index];
			break;
		}

		int sum = plus_group[index] + plus_group[index + 1];
		int mul = plus_group[index] * plus_group[index + 1];
		sum > mul ? result += plus_group[index] : (result += mul, index++);
	}

	for (int index = 0; index < minus_group.size(); index++)
	{
		if (index == minus_group.size() - 1)
		{
			result += minus_group[index];
			break;
		}

		int sum = minus_group[index] + minus_group[index + 1];
		int mul = minus_group[index] * minus_group[index + 1];
		sum > mul ? result += minus_group[index] : (result += mul, index++);
	}
}

int main()
{
	input_data();
	
	solved();
	
	cout << result << endl;
}