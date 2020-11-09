/**
 * @date 20.11.06
 * @url https://www.acmicpc.net/problem/10610
 * @result 실패 런타임 에러
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string N;
int result = 0;

void solved()
{
	sort(N.begin(), N.end(), greater<>());

	int sum = 0;
	for (auto ch_num : N)
		sum += ch_num - '0';

	if (sum % 3 != 0 || N[N.size() - 1] != '0')
		result = -1;

	else
		result = stoi(N);
}

int main()
{
	cin >> N;

	solved();

	cout << result << endl;
}
