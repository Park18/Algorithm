/**
 * @date 20.11.17
 * @url https://www.acmicpc.net/problem/11657
 * @result ¼º°ø
 */

#include <iostream>
#include <vector>

using namespace std;

#define INF 2e9

struct edge_info
{
	int from;
	int to;
	int cost;

	edge_info(int from, int to, int cost) :from(from), to(to), cost(cost) {};
};

int N, M;
vector<edge_info> graph;

void input_data()
{
	cin >> N >> M;
	for (int index = 0; index < M; index++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		//graph[index].from = from;
		//graph[index].to = to;
		//graph[index].cost = cost;

		graph.push_back(edge_info(from, to, cost));
	}
}

void solved()
{
	vector<long long> dist(N + 1, INF);
	dist[1] = 0;

	for (int loop = 1; loop <= N - 1; loop++)
	{
		for (int index = 0; index < graph.size(); index++)
		{
			int from = graph[index].from;
			int to = graph[index].to;
			int cost = graph[index].cost;

			if (dist[from] == INF)
				continue;

			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int index = 0; index < graph.size(); index++)
	{
		int from = graph[index].from;
		int to = graph[index].to;
		int cost = graph[index].cost;

		if (dist[from] == INF)
			continue;

		if (dist[to] > dist[from] + cost)
		{
			cout << -1 << endl;
			return;
		}
	}

	for (int city = 2; city <= N; city++)
	{
		if (dist[city] == INF)
			dist[city] = -1;

		cout << dist[city] << endl;
	}
}

int main()
{
	input_data();

	solved();
}