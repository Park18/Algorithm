/**
 * @date 20.06.03
 * @brief BOJ 2178
 * @url https://www.acmicpc.net/problem/2178
 */

#include <iostream>
#include <string>
#include <queue>

#define left -1
#define right 1
#define up -1
#define down 1

using namespace std;

class pos
{
public:
	int x;
	int y;
	int count;

	pos(int x, int y, int count) : x(x), y(y), count(count) {}
};

int N, M;
std::string map[100];
bool visit[100][100] = { false };

void input()
{
	cin >> N >> M;

	for (int x = 0; x < N; x++)
		cin >> map[x];
}

void bfs()
{
	queue<pos> wait_queue;
	wait_queue.push(pos(0, 0, 1));
	int program_count = 0;

	for (; !wait_queue.empty();)
	{
		int row = wait_queue.front().x;
		int col = wait_queue.front().y;
		int count = wait_queue.front().count;
		wait_queue.pop();
		visit[row][col] = true;

		program_count++;

		if (row == N - 1 && col == M - 1)
		{
			cout << count << endl;
			cout << program_count << endl;
			return;
		}

		// 4가지 경우
		// 좌, 우, 상, 하
		// 좌
		if (0 <= col - 1 && map[row][col - 1] == '1' && !visit[row][col - 1])
			wait_queue.push(pos(row, col - 1, count + 1));

		// 우
		if (col + 1 < M && map[row][col + 1] == '1' && !visit[row][col + 1])
			wait_queue.push(pos(row, col + 1, count + 1));

		// 상
		if (0 <= row - 1 && map[row - 1][col] == '1' && !visit[row - 1][col])
			wait_queue.push(pos(row - 1, col, count + 1));

		// 하
		if (row + 1 < N && map[row + 1][col] == '1' && !visit[row + 1][col])
			wait_queue.push(pos(row + 1, col, count + 1));
	}
}

int main()
{
	input();
	bfs();
}