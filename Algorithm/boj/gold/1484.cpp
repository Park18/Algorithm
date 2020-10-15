/**
 * @date 20.10.13
 * @url https://www.acmicpc.net/problem/1484
 * @result 성공
 */

#include <iostream>
#include <vector>

#define POW(x) (x * x)
#define MAX 11
using namespace std;

int table[MAX];
int G;
vector<int> result;

long long pow(int x)
{
	return (long long)x * x;
}

void solved()
{
	int x = 1;
	int y = 1;
	int g = 0;

	// 중단 조건 이해 못하겠음
	while (!(x - y == 1 && g > G))
	{
		if (g >= G)
			g = pow(x) - pow(++y);

		else
			g = pow(++x) - pow(y);

		if (g == G)
			result.push_back(x);
	}
}

int main()
{
	cin >> G;

	solved();

	if (result.empty())
	{
		cout << -1 << endl;
		return 0;
	}

	for (auto num : result)
		cout << num << endl;
}