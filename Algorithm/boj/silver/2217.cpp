/**
 * @date 20.10.30
 * @url https://www.acmicpc.net/problem/2217
 * @reuslt ¼º°ø
 */

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 100000

using namespace std;

int N;
int rope_group[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];
int result = 0;

bool compare(int a, int b)
{
	return a > b;
}

void input_data()
{
	cin >> N;

	for (int rope = 1; rope <= N; rope++)
		cin >> rope_group[rope];
}

void solved()
{
	sort(rope_group + 1, rope_group + (N + 1), compare);

	result = dp[1] = rope_group[1];
	for (int rope = 2; rope <= N; rope++)
		result = dp[rope] = max(result, rope_group[rope] * rope);
}

int main()
{
	input_data();

	solved();

	cout << result << endl;
}