/**
 * @date 20.06.16
 * @brief BOJ 11724
 * @url https://www.acmicpc.net/problem/11724
 */

#include <iostream>

int N;			// 정점 개수
int M;			// 간선 개수
bool** graph;	// 그래프
bool** visit;	// 방문 기록
int ans = 0;

using namespace std;

void init()
{
	graph = new bool* [N];
	visit = new bool* [N];
	for (int row = 0; row < N; row++)
	{
		graph[row] = new bool[N];
		visit[row] = new bool[N];
	}

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			graph[row][col] = false;
			visit[row][col] = false;
		}
	}
}

void input()
{
	cin >> N >> M;
	init();

	for (int loop = 0; loop < M; loop++)
	{
		int node1, node2;
		cin >> node1 >> node2;
	
		graph[node1 - 1][node2 - 1] = true;
		graph[node2 - 1][node1 - 1] = true;	
	}
}


void DFS(int row, int col)
{
	visit[row][col] = true;
	visit[col][row] = true;

	int next_row = col;
	for (int next_col = 0; next_col < N; next_col++)
	{
		if (graph[next_row][next_col] && !visit[next_row][next_col])
			DFS(next_row, next_col);
	}
}

int main()
{
	input();
	
	for (int row = 0; row < N; row++)
	{
		int zero_count = 0;

		for (int col = 0; col < N; col++)
		{
			if (graph[row][col] && !visit[row][col])
			{
				DFS(row, col);
				ans++;
			}

			if (!graph[row][col])
			{
				zero_count++;
				if (zero_count == N) ans++;
			}
		}
	}
	
	cout << ans << endl;
}