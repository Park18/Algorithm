/**
 * @date 20.11.13
 * @url https://www.acmicpc.net/problem/18352
 * @result 성공
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

struct edge_info
{
	int to;
	int cost;

	edge_info() {};
	edge_info(int to, int cost) :to(to), cost(cost) {};
};

struct upper
{
	bool operator() (edge_info a, edge_info b)
	{
		return a.cost > b.cost;
	}
};

int N, M, K, X; // 도시의 수, 도로의 개수, 최단 거리, 출발 도시
vector<vector<edge_info>> graph;
vector<int> result;

void input_data()
{
	cin >> N >> M >> K >> X;

	graph.assign(N + 1, vector<edge_info>(0));
	for (int loop = 0; loop < M; loop++)
	{
		int from, to;
		cin >> from >> to;

		graph[from].push_back({ to, 1 });
	}
}

void solved(int start)
{
	vector<int> dist(N + 1, INF);
	dist[start] = 0;

	priority_queue <edge_info, vector<edge_info>, upper> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int visit = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();

		for (int index = 0; index < graph[visit].size(); index++)
		{
			int next = graph[visit][index].to;
			int next_dist = graph[visit][index].cost;

			if (dist[next] > cost + next_dist)
			{
				dist[next] = cost + next_dist;
				pq.push({ next, dist[next] });
			}
		}
	}

	for (int city = 1; city <= N; city++)
		if (dist[city] == K)
			result.push_back(city);
}

int main()
{
	input_data();

	solved(X);

	if (result.empty())
		cout << -1 << endl;
	else
		for (auto city : result)
			cout << city << endl;
}