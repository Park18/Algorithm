/**
 * @date 20.11.08
 * @url https://www.acmicpc.net/problem/11399
 * @result ¼º°ø
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> P;
int result = 0;

void input_data()
{
	cin >> N;
	for (int loop = 0; loop < N; loop++)
	{
		int p;
		cin >> p;
		P.push_back(p);
	}
}

void solved()
{
	sort(P.begin(), P.end());

	int sum = 0;
	for (auto p : P)
	{
		sum += p;
		result += sum;
	}
}

int main()
{
	input_data();

	solved();

	cout << result << endl;
}