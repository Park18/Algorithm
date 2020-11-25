/**
 * @date 20.10.03
 * @url https://www.acmicpc.net/problem/2056
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct NODE
{
	int start_time;
	int working_time;
	int end_time;
};

#define GRAPH vector<int>
#define MAX 500

int N;
NODE node_group[MAX + 1];
GRAPH graph[MAX + 1];
int in_degree[MAX + 1];
int result = 0;

int dp[MAX + 1];

void input_data()
{
	cin >> N;
	for (int node = 1; node <= N; node++)
	{
		int time;
		cin >> time;

		node_group[node].working_time = time;

		int parent = 0;
		while(true)
		{
			cin >> parent;
			if (parent == -1)
				break;

			graph[parent].push_back(node);
			in_degree[node]++;
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
		int node = wait_queue.front();
		wait_queue.pop();

		// �湮 ��� ���� �ð� ����
		// ��� �� ����
		node_group[node].end_time = node_group[node].start_time + node_group[node].working_time;
		result = max(result, node_group[node].end_time);

		// �湮 ����� �ڽ� ��� ���� �ð� ����(max(�ڽ� ����, �湮 ����))
		// �湮 ����� �ڽ� ����� ���� ���� ����
		// �湮 ����� �ڽ� ����� ���� ������ 0�̸� ť�� Ǫ��
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
	input_data();
	solved();

	for (int node = 1; node <= N; node++)
		cout << node_group[node].end_time << endl;
}