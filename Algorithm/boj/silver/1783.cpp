/**
 * @date 20.11.07
 * @url https://www.acmicpc.net/problem/1783
 * @result ¼º°ø
 */

#include <iostream>

using namespace std;

int N, M;
int result;

void solved()
{
	if (N == 1)
		result = 1;
	
	else if (N == 2)
	{
		if (M <= 2)
			result = 1;

		else if (M <= 4)
			result = 2;

		else if (M <= 6)
			result = 3;

		else
			result = 4;
	}

	else
	{
		if (M <= 6)
		{
			if (4 <= M)
				result = 4;

			else
				result = M;
		}

		else
			result = M - 2;
	}
}

int main()
{
	cin >> N >> M;

	solved();

	cout << result << endl;
}