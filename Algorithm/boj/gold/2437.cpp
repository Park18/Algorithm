/**
 * @date 20.11.01
 * @url https://www.acmicpc.net/problem/2437
 * @reuslt ¼º°ø
 * @comment https://m.blog.naver.com/PostView.nhn?blogId=hongjg3229&logNo=221627349685&proxyReferer=https:%2F%2Fwww.google.com%2F
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
//int weight_group[1000];
vector<int> weight_group;
int result;

void input_data()
{
	cin >> N;
	for (int loop = 0; loop < N; loop++)
	{
		int weight;
		cin >> weight;
		weight_group.push_back(weight);
	}
}

void solved()
{
	sort(weight_group.begin(), weight_group.end());
	
	int sum = 0;
	for (int weight : weight_group)
	{
		if (sum + 2 <= weight)
			break;

		sum += weight;
	}

	result = sum + 1;
}

int main()
{
	input_data();

	solved();

	cout << result << endl;
}