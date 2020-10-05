/**
 * @date 20.10.04
 * @url https://www.acmicpc.net/problem/2252
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 32000

int N, M;
vector<int> graph[MAX + 1];
int in_degree[MAX + 1];
vector<int> order;

void input_data()
{
	cin >> N >> M;

	for (int loop = 0; loop < M; loop++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		in_degree[to]++;
	}
}

void solved()
{
	priority_queue<int, vector<int>, greater<int>> wait_queue;
	for (int node = 1; node <= N; node++)
		if (in_degree[node] == 0)
			wait_queue.push(node);

	for (int loop = 0; loop < N; loop++)
	{
		order.push_back(wait_queue.top());
		wait_queue.pop();

		int node = order[order.size() - 1];
		for (int index = 0; index < graph[node].size(); index++)
		{
			int next_node = graph[node][index];
			in_degree[next_node]--;

			if (in_degree[next_node] == 0)
				wait_queue.push(next_node);
		}
	}
}

int main()
{
	input_data();
	solved();

	for (int node : order)
		cout << node << " ";
}