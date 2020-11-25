/**
 * @date 20.11.15
 * @url https://www.acmicpc.net/problem/1446
 * @result pair를 쓰기 싫어서 만들었는데 우선순위 큐에서 막힘
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class load_info
{
	int to;
	int cost;

	load_info(int to, int cost) :to(to), cost(cost) {};
};

int N, D;
vector<vector<load_info>> graph;

void input_data()
{
	cin >> N >> D;

	graph.assign(N, vector<load_info>());
	for (int loop = 0; loop < N; loop++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(load_info(to, cost));
	}
}

void solved(int start)
{
	vector<int> dist(N, INFINITY);
	dist[start] = 0;

	priority_queue<load_info> pq;
	pq.push(load_info(start, 0));

	while (!pq.empty())
	{
		int visit = pq.top().to;
		int cost = -pq.top().cost;
		pq.pop();

		if (dist[visit] < cost)
			continue;

		for (int index = 0; index < graph[visit].size(); index++)
		{
			int next = graph[visit][index].to;
			int next_dist = cost + graph[visit][index].cost;

			if (next_dist < dist[next] && next <= D)
			{
				dist[next] = next_dist;
				pq.push(load_info(next, -next_dist));
			}
		}
	}

	for (auto cost : dist)
		cout << cost << ' ';
}

int main()
{
	input_data();

	solved(0);
}