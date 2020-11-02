/**
 * @date 20.10.31
 * @url https://www.acmicpc.net/problem/1744
 * @reuslt ½ÇÆÐ
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 10000
#define MIN_VALUE -100000000

using namespace std;

int N;
int sequence[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];
int result = MIN_VALUE;

void input_data()
{
	cin >> N;
	for (int index = 1; index <= N; index++)
		cin >> sequence[index];
}

void solved()
{
	sort(sequence + 1, sequence + (N + 1));

	result = dp[1] = sequence[1];
	for (int index = 2; index <= N; index++)
		result = dp[index] = max(result, max(dp[index - 2] + sequence[index - 1] + sequence[index], dp[index - 2] + (sequence[index - 1] * sequence[index])));
}

int main()
{
	input_data();

	solved();

	cout << result << endl;
}