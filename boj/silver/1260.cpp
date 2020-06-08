#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N; // 정점 개수
int M; // 간선 개수
int V; // 시작 위치
int graph[1000][1000] = { 0 }; // 그래프 배열 포인터
vector<int> visit; // 방문을 저장하는 배열 포인터
queue<int> wait_queue;

void print_dfs(int start_index)
{
	visit.push_back(start_index);
	cout << start_index + 1 << " ";

	for (int node_index = 0; node_index < N; node_index++)
	{
		// start_index
		//  ↓
		// [ ][0][1][2][3] ← node_index
		// [0] 0  1  1  1
		// [1] 1  0  0  1
		// [2] 1  0  0  1
		// [3] 1  1  1  0
		// 자기 자신의 경우와 이미 방문한 노드일 경우 넘어간다.
		if (node_index == start_index || find(visit.begin(), visit.end(), node_index) != visit.end())
			continue;

		// 자신이 아니고 방문하지 않은 노드가 연결된 경우(1) 재귀 함수로 호출한다.
		if (graph[start_index][node_index] == 1)
			print_dfs(node_index);
	}
}

void print_bfs()
{
	for (int start_index = V - 1; visit.size() < M + 1; )
	{
		cout << start_index + 1 << " ";
		visit.push_back(start_index);

		for (int node_index = 0; node_index < N; node_index++)
		{
			if (node_index == start_index || find(visit.begin(), visit.end(), node_index) != visit.end())
				continue;

			if (graph[start_index][node_index] == 1)
				if (find(visit.begin(), visit.end(), node_index) == visit.end())
					wait_queue.push(node_index);
		}

		if (!wait_queue.empty())
		{
			start_index = wait_queue.front();
			wait_queue.pop();
		}
	}

	//wait_queue.push(V - 1);
	//while(!wait_queue.empty())
	//{
	//	// start_index
	//	//  ↓
	//	// [ ][0][1][2][3] ← node_index
	//	// [0] 0  1  1  1
	//	// [1] 1  0  0  1
	//	// [2] 1  0  0  1
	//	// [3] 1  1  1  0
	//	int start_index = wait_queue.front();
	//	wait_queue.pop();

	//	// 출력후 방문 기록
	//	cout << start_index + 1 << " ";
	//	visit.push_back(start_index);

	//	for (int node_index = 0; node_index < N; node_index++)
	//	{
	//		if (node_index == 0 || find(visit.begin(), visit.end(), node_index) != visit.end())
	//			continue;

	//		if (graph[start_index][node_index] == 1)
	//			wait_queue.push(node_index);
	//	}

	//	if (find(visit.begin(), visit.end(), wait_queue.front()) != visit.end())
	//		wait_queue.pop();
	//}
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int n1 = 0;
		int n2 = 0;
		cin >> n1 >> n2;

		graph[n1 - 1][n2 - 1] = 1;
		graph[n2 - 1][n1 - 1] = 1;
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << graph[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	print_dfs(V - 1);
	cout << '\n';
	visit.clear();
	print_bfs();
}