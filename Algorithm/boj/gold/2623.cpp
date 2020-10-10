/**
 * @date 20.10.07
 * @url https://www.acmicpc.net/problem/2623
 * @result 성공
 */

#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

int N, M;
vector<int> graph[MAX + 1];
int in_degree[MAX + 1];
vector<int> order;

void input_data()
{
	cin >> N >> M;
	for (int loop = 0; loop < M; loop++)
	{
		int count;
		cin >> count;

		int parent = 0;
		int children = 0;
		for (int sub_loop = 0; sub_loop < count; sub_loop++)
		{
			cin >> children;

			if (parent != 0)
			{
				graph[parent].push_back(children);
				in_degree[children]++;
			}

			parent = children;
		}
	}
}

void solved()
{
	queue<int> wait_queue;
	for (int node = 1; node <= N; node++)
		if (in_degree[node] == 0)
			wait_queue.push(node);

	for (int loop = 0; loop < N; loop++)
	{
		// 싸이클 발생
		if (wait_queue.empty())
		{
			order.clear();
			order.push_back(0);
			return;
		}

		int node = wait_queue.front();
		wait_queue.pop();

		order.push_back(node);

		for (int next_node = 0; next_node < graph[node].size(); next_node++)
		{
			if (--in_degree[graph[node][next_node]] == 0)
				wait_queue.push(graph[node][next_node]);
		}
	}
}

int main()
{
	input_data();
	solved();

	for (int index = 0; index < order.size(); index++)
		cout << order[index] << endl;
}