/**
 * @date 20.11.20
 * @url https://www.acmicpc.net/problem/1520
 * @result ½ÇÆÐ
 */

#include <iostream>
#include <cstring>
#include <queue>

#define MAX_SIZE 500

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int N, M;

int row_mov[] = { -1, 1, 0, 0 }; // »ó ÇÏ ÁÂ ¿ì
int col_mov[] = { 0, 0, -1, 1 }; // »ó ÇÏ ÁÂ ¿ì

void input_data()
{
	cin >> M >> N;
	for (int m = 0; m < M; m++)
		for (int n = 0; n < N; n++)
			cin >> map[m][n];

	memset(visit, false, MAX_SIZE * MAX_SIZE);
}

int dfs(int row, int col)
{
	if (row == M - 1 && col == N - 1)
		return 1;

	visit[row][col] = true;
	int count = 0;

	for (int way = 0; way < 4; way++)
	{
		int next_row = row + row_mov[way];
		int next_col = col + col_mov[way];

		if ((0 <= next_row && next_row < M) && (0 <= next_col && next_col < N) && 
			map[row][col] > map[next_row][next_col] && !visit[next_row][next_col])
		{
			count += dfs(next_row, next_col);
			visit[next_row][next_col] = false;
		}
	}

	return count;
}

int bfs()
{
	queue<pair<int, int>> wait_queue;
	wait_queue.push(make_pair(0, 0));

	int count = 0;
	while (!wait_queue.empty())
	{
		int row = wait_queue.front().first;
		int col = wait_queue.front().second;
		wait_queue.pop();

		if (row == M - 1 && col == N - 1)
			count++;

		for (int way = 0; way < 4; way++)
		{
			int next_row = row + row_mov[way];
			int next_col = col + col_mov[way];

			if ((0 <= next_row && next_row < M) && (0 <= next_col && next_col < N) &&
				map[row][col] > map[next_row][next_col])
			{
				wait_queue.push(make_pair(next_row, next_col));
			}
		}
	}

	return count;
}

int main()
{
	input_data();

	cout << bfs() << endl;
}