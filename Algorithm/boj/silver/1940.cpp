/**
 * @date 20.10.27
 * @url https://www.acmicpc.net/problem/1940
 * @result ¼º°ø
 */

#include <iostream>
#include <algorithm>

#define MAX 15000

using namespace std;

int N;
int M;
int material[MAX];
int count;

void input_data()
{
	cin >> N >> M;

	for (int index = 0; index < N; index++)
		cin >> material[index];
}

void solved()
{
	sort(material, material + N);

	int start = 0;
	int end = N - 1;

	while (start < end)
	{
		int sum = material[start] + material[end];

		if (sum == M)
			start++, end--, ::count++;

		else if (sum < M)
			start++;

		else
			end--;
	}
}

int main()
{
	input_data();

	solved();

	cout << ::count << endl;
}