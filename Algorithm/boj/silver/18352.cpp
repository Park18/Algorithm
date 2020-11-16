/**
 * @date 20.11.13
 * @url https://www.acmicpc.net/problem/18352
 * @result 메모리초과
 */

#include <iostream>
#include <vector>

using namespace std;

#define INF 300000

int N, M, K, X;
vector<int> graph[300000];
vector<int> cost_group;
vector<bool> visit;
vector<int> result;

void input_data()
{
	cin >> N >> M >> K >> X;	

	for (int city = 0; city < M; city++)
	{
		graph[city].assign(N, INF);
		graph[city][city] = 0;
	}

	for (int loop = 0; loop < M; loop++)
	{
		int from, to;
		cin >> from >> to;

		graph[from - 1][to - 1] = 1;
		graph[to - 1][from - 1] = 1;
	}

	visit.assign(N, false);
	cost_group.assign(N, 0);
}

int get_min_cost_index()
{
	int min = INF;
	int index = 0;

	for (int city = 0; city < N; city++)
	{
		if (cost_group[city] < min && !visit[city])
		{
			min = cost_group[city];
			index = city;
		}
	}

	return index;
}

void solved(int row)
{
	for (int city = 0; city < N; city++)
		cost_group[city] = graph[row][city];

	visit[row] = true;
	for (int loop = 0; loop < N - 2; loop++)
	{
		int next_city = get_min_cost_index();
		visit[next_city] = true;

		for (int col = 0; col < M; col++)
		{
			if (!visit[col])
				if (cost_group[next_city] + graph[next_city][col] < cost_group[col])
					cost_group[col] = cost_group[next_city] + graph[next_city][col];		
		}
	}

	for (int city = 0; city < N; city++)
		if (cost_group[city] == K)
			result.push_back(city + 1);
}

int main()
{
	input_data();

	solved(X - 1);

	if (result.empty())
		cout << -1 << endl;
	else
		for (int index = 0; index < result.size(); index++)
			cout << result[index] << endl;
}