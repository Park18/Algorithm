/**
 * @date 20.11.04
 * @url https://www.acmicpc.net/problem/1202
 * @result 성공
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
vector<pair<int, int>> jewely_group; // m, v
vector<int> bag_group;
long long sum = 0;

void input_data()
{
	cin >> N >> K;

	for (int loop = 0; loop < N; loop++)
	{
		int m, v;
		cin >> m >> v;
		jewely_group.push_back(make_pair( m, v ));
	}

	for (int loop = 0; loop < K; loop++)
	{
		int k;
		cin >> k;
		bag_group.push_back(k);
	}
}


void solved()
{
	sort(jewely_group.begin(), jewely_group.end()); // 비교함수 지정 안하면 first 먼저 비교함
	sort(bag_group.begin(), bag_group.end());

	priority_queue<int> pq; // 높은 값이 우선순위 높음
	for (int bag_index = 0, jewly_index = 0; bag_index < K; bag_index++)
	{
		for (; jewly_index < N && jewely_group[jewly_index].first <= bag_group[bag_index];)
			pq.push(jewely_group[jewly_index++].second);
		
		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
}

int main()
{
	input_data();

	solved();

	cout << sum << endl;
}