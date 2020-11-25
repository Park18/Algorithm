/**
 * @date 20.11.18
 * @url https://www.acmicpc.net/problem/1219
 * @result ½ÇÆÐ
 * @source_url https://colorscripter.com/s/KVWmj2C
 */

#include <iostream>
#include <vector>

#define INF -987654321
#define endl '\n'

using namespace std;

struct edge_info
{
	int from;
	int to;
	int cost;

	edge_info(int from, int to, int cost) :from(from), to(to), cost(cost) {};
};

int N, start, end, M;
vector<edge_info> graph;
vector <int> income_group;

void input_data()
{
	cin >> N >> start >> ::end >> M;	

	for (int loop = 0; loop < M; loop++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph.push_back(edge_info(from, to, -cost));
	}

	for (int city = 0; city < N; city++)
	{
		int income;
		cin >> income;
		income_group.push_back(income);
	}
}

void solved()
{
	vector<int> dist(N, INF);
	dist[start] = income_group[start];

	for (int loop = 0; loop < N; loop++)
	{
		for (int index = 0; index < graph.size(); index++)
		{
			int from = graph[index].from;
			int to = graph[index].to;
			int cost = graph[index].cost;

			if (dist[from] == INF)
				continue;

			if (dist[to] < dist[from] + cost + income_group[to])
				dist[to] = dist[from] + cost + income_group[to];
		}
	}

	if (dist[::end] == INF)
	{
		cout << "gg" << endl;
		return;
	}

	for (int index = 0; index < graph.size(); index++)
	{
		int from = graph[index].from;
		int to = graph[index].to;
		int cost = graph[index].cost;

		if (dist[from] == INF)
			continue;

		if ((to == ::end) && (dist[to] < dist[from] + cost + income_group[to]))
		{
			cout << "Gee" << endl;
			return;
		}
	}

	cout << dist[::end] << endl;
}

int main()
{
	input_data();

	solved();
}