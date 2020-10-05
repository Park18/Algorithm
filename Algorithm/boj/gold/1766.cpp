/**
 * @date 20.10.02
 * @url https://www.acmicpc.net/problem/1766
 * @context 사이클이 발생하는 그래프를 그리지 않는 다는 가정하에 설계된 알고리즘
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define GRAPH vector<int>
#define NODE int
#define MAX 32000

int N, M;

GRAPH graph[MAX + 1];
int in_degree[MAX + 1];
vector<int> solved_order;

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
	priority_queue<int, vector<int>, greater<int>>wait_queue;
	for (int node = 1; node <= N; node++)
	{
		if (in_degree[node] == 0)
			wait_queue.push(node);
	}

	while (!wait_queue.empty())
	{
		solved_order.push_back(wait_queue.top());
		wait_queue.pop();
	
		int node = solved_order[solved_order.size() - 1];
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
	
	for (int node : solved_order)
		cout << node << " ";
}