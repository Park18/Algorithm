/**
 * @date 20.10.14
 * @url https://www.acmicpc.net/problem/2470
 * @result 성공
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2000000000

using namespace std;

int N;
vector<int> solution; // 용액
int result[2];

bool compare(int a, int b)
{
	return abs(a) > abs(b);
}

void input_data()
{
	cin >> N;

	for (int loop = 0; loop < N; loop++)
	{
		int value;
		cin >> value;
		solution.push_back(value);
	}
}

void solved()
{
	int approximate_value_to_zero = MAX;

	for (int index = 0; index < N - 1; index++)
	{
		if (abs(solution[index] + solution[index + 1]) < approximate_value_to_zero)
		{
			approximate_value_to_zero = abs(solution[index] + solution[index + 1]);
			result[0] = solution[index];
			result[1] = solution[index + 1];
		}
	}
}

int main()
{
	input_data();

	sort(solution.begin(), solution.end(), compare);
	solved();

	if (result[0] < result[1])
		cout << result[0] << ' ' << result[1] << endl;
	else
		cout << result[1] << ' ' << result[0] << endl;
}