/**
 * @date 20.10.12
 * @url https://www.acmicpc.net/problem/2531
 * @result ½ÇÆÐ
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, d, k, c;
vector<int> link_info;
vector<int> belt;
vector<int> result;

void input_data()
{
	cin >> N >> d >> k >> c;

	for (int loop = 0; loop < N; loop++)
	{
		int sushi;
		cin >> sushi;
		belt.push_back(sushi);
	}

	for (int index = 0; index < N - 1; index++)
		link_info.push_back(index + 1);
	link_info.push_back(0);
}

void solved()
{
	for (int base = 0; base < N - k; base++)
	{
		for (int index = 0; index < k; index++)
		{
			int sushi = belt[link_info[base + index]];

			if (sushi == c || find(result.begin(), result.end(), sushi) != result.end())
			{
				result.clear();
				break;
			}

			result.push_back(sushi);
		}
	}
}

int main()
{
	input_data();

	solved();

	if (result.size() < k)
		cout << result.size() << endl;
	else
		cout << result.size() + 1 << endl;
}