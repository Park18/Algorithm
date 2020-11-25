/**
 * @date 20.10.06
 * @url https://www.acmicpc.net/problem/1005
 * @result 성공
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct NODE
{
	int start_time;
	int working_time;
	int end_time;
};

#define GRAPH vector<int>
#define MAX 1000

int T, N, K, W;
NODE node_group[MAX + 1];
GRAPH graph[MAX + 1];
int in_degree[MAX + 1];
vector<int> result_group;

void input_data()
{
	cin >> N >> K;

	for (int node = 1; node <= N; node++)
	{
		int time;
		cin >> time;
		node_group[node].working_time = time;
	}

	for (int loop = 0; loop < K; loop++)
	{
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		in_degree[to]++;
	}

	cin >> W;
}

void solved()
{
	queue<int> wait_queue;
	for (int node = 1; node <= N; node++)
		if (in_degree[node] == 0)
			wait_queue.push(node);

	for (int loop = 0; loop < N; loop++)
	{
		int node = wait_queue.front();
		wait_queue.pop();

		// 방문 노드 종료 시간 갱신
		// 결과 값 갱신
		node_group[node].end_time = node_group[node].start_time + node_group[node].working_time;

		// 방문 노드의 자식 노드 시작 시간 갱신(max(자식 시작, 방문 종료))
		// 방문 노드의 자식 노드의 진입 차수 제거
		// 방문 노드의 자식 노드의 진입 차수가 0이면 큐에 푸쉬
		for (int index = 0; index < graph[node].size(); index++)
		{
			int children = graph[node][index];
			node_group[children].start_time = max(node_group[children].start_time, node_group[node].end_time);

			in_degree[children]--;
			if (in_degree[children] == 0)
				wait_queue.push(children);
		}
	}
}

int main()
{
	cin >> T;
	for (int loop = 0; loop < T; loop++)
	{
		input_data();
		solved();
		result_group.push_back(node_group[W].end_time);

		memset(node_group, 0, sizeof(node_group));
		memset(graph, 0, sizeof(graph));
		memset(in_degree, 0, sizeof(in_degree));
	}

	for (auto result : result_group)
		cout << result << endl;
}