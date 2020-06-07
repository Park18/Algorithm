/**
 * @date 20.05.17
 * @brief BOJ 1012
 * @url https://www.acmicpc.net/problem/1012
 */

#include <iostream>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

using namespace std;
int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M, N, K;
		cin >> M >> N >> K;

		int map[MAX_WIDTH][MAX_HEIGHT] = { 0 };
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		//print_map(map, N, M);

		int count = 0;
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				if (x == 0 && y == 0)
				{
					if (map[x][y] == 1)
						count++;
				}

				else if (x == 0)
				{
					if (map[x][y - 1] == 0 && map[x][y] == 1)
						count++;
				}

				else if (y == 0)
				{
					if (map[x - 1][y] == 0 && map[x][y] == 1)
						count++;
				}

				else
				{
					if (map[x - 1][y] == 0 && map[x][y] && map[x][y - 1] == 0 && map[x][y] == 1)
					{
						if (map[x - 1][y - 1] == 0 && map[x - 1][y] == 1 && map[x][y - 1] == 1 && map[x][y] == 1)
							count--;
						count++;
					}
				}
			}
		}

		cout << "result = " << count << endl;
	}
}