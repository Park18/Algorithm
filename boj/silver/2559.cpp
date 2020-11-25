/**
 * @date 20.10.25
 * @url https://www.acmicpc.net/problem/2559
 * @result ¼º°ø
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> temp_group;
int N, K;
int result = -1000000000;

void input_data()
{
	cin >> N >> K;
	for (int index = 0; index < N; index++)
	{
		int temp;
		cin >> temp;
		temp_group.push_back(temp);
	}
}

void solved()
{
	int start = 0;
	int end = K - 1;
	int sum = 0;

	for (int index = 0; index < K; index++)
		sum += temp_group[index];
	result = max(result, sum);

	while (end != N - 1)
	{
		sum -= temp_group[start++];
		sum += temp_group[++end];

		result = max(result, sum);
	}
}

int main()
{
	input_data();

	solved();

	cout << result << endl;
}