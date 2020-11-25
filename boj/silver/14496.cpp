/**
 * @date 20.11.14
 * @url https://www.acmicpc.net/problem/14496
 * @result
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000

using namespace std;

int a, b;
int N, M;
vector<vector<pair<int, int>>> graph; // 노드, 비용
vector<int> dist;

void input_data()
{
	cin >> a >> b;
	cin >> N >> M;

	graph.assign(N, vector<pair<int, int>>());
	for (int loop = 0; loop < M; loop++)
	{
		int from, to;
		cin >> from >> to;
		graph[from - 1].push_back(make_pair(to - 1, 1));
		graph[to - 1].push_back(make_pair(from - 1, 1));
	}
}

void solved(int start)
{
	dist.assign(N, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq; // 
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int visit = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (dist[visit] < cost)
			continue;

		for (int index = 0; index < graph[visit].size(); index++)
		{
			int next = graph[visit][index].first;
			int next_dist = cost + graph[visit][index].second;

			if (dist[next] > next_dist)
			{
				dist[next] = next_dist;
				pq.push(make_pair(next, -next_dist));
			}
		}
	}
}

int main()
{
	input_data();

	solved(a - 1);

	cout << dist[b - 1] << endl;
}