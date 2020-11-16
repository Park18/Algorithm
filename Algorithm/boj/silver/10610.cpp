/**
 * @date 20.11.06
 * @url https://www.acmicpc.net/problem/10610
 * @result ¼º°ø
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string N;

void solved()
{
	sort(N.begin(), N.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N.size(); i++)
		sum += N[i] - '0';

	if (sum % 3 != 0 || N[N.size() - 1] != '0')
		cout << -1 << endl;

	else
		cout << N << endl;
}

int main()
{
	cin >> N;

	solved();
}