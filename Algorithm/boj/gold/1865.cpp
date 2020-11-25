/**
 * @date 20.11.16
 * @url https://www.acmicpc.net/problem/1865
 * @result ����
 */

#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

struct edge_info
{
	int start;
	int end;
	int cost;

	edge_info() {};
	edge_info(int start, int end, int cost) : start(start), end(end), cost(cost) {};
};

vector<edge_info> graph;
int test_case;
int N, M, W;

void input_data()
{
	cin >> N >> M >> W;

	for (int loop = 0; loop < M; loop++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph.push_back(edge_info(start, end, cost));
		graph.push_back(edge_info(end, start, cost));
	}

	for (int loop = 0; loop < W; loop++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph.push_back(edge_info(start, end, -cost));
	}
}

string solved()
{
	vector<int> dist(N + 1, INF);

	dist[1] = 0;
	for (int loop = 1; loop <= N - 1; loop++)
	{
		for (int index = 0; index < graph.size(); index++)
		{
			int start = graph[index].start;
			int end = graph[index].end;
			int cost = graph[index].cost;
			
			// �������� ����Ǿ� ���� ���� �׷������� �߻��ϴ�
			// ���� ����Ŭ�� ��ƾ� �ϱ� ������ �Ʒ��� if���� �����Ѵ�.
			// if (dist[start] == INF)
			// 	continue;

			if (dist[end] > dist[start] + cost)
				dist[end] = dist[start] + cost;
		}
	}

	for (int index = 0; index < graph.size(); index++)
	{
		int start = graph[index].start;
		int end = graph[index].end;
		int cost = graph[index].cost;
	
		if (dist[end] > dist[start] + cost)
			return "YES";
	}
	
	return "NO";
}

int main()
{
	cin >> test_case;

	for (int loop = 0; loop < test_case; loop++)
	{
		input_data();

		cout << solved() << endl;

		graph.clear();
	}
}