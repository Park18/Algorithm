#include <iostream>
#include <algorithm>

int N;
int map[100][100] = { 0 };
bool visit[100][100] = { false };

// 위, 아래, 오른쪽, 왼쪽
int move_row[4] = {-1, +1, 0, 0};
int move_col[4] = {0, 0, +1, -1};

using namespace std;

void input()
{
	cin >> N;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			cin >> map[row][col];
}

void clear()
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			visit[row][col] = false;
}

bool DFS(int row, int col, int water_size)
{
	visit[row][col] = true;

	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		if (0 <= next_row && next_row < N && 0 <= next_col && next_col < N && 
			!visit[next_row][next_col] && water_size < map[next_row][next_col])
		{
			DFS(next_row, next_col, water_size);
			return true;
		}
	}

	return false;
}

int main()
{
	input();

	int max_size = 1;
	for (int water_size = 0; water_size <= 100; water_size++)
	{
		int count = 0;
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
			{
				if(water_size < map[row][col])
					if (DFS(row, col, water_size))
						count++;
			}
		}

		max_size = max(max_size, count);
		clear();
	}

	cout << max_size << endl;
}