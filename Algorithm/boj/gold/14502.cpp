/**
 * @date 20.06.15
 * @brief BOJ 14502
 * @url https://www.acmicpc.net/problem/14502
 */

#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 8

class pos
{
public:
	int row;
	int col;

	pos(int row, int col) :row(row), col(col) {}
};

int N;				// row_size
int M;				// col_size
int lab[MAX][MAX];	// ������
int tmp[MAX][MAX];	// ������ ���纻
int ans;			// ���

std::queue<pos> wait_queue; // ��� ť

int move_row[] = { 0, 0, -1, 1 }; // ��, ��, ��, ��
int move_col[] = { -1, 1, 0, 0 }; // ��, ��, ��, ��

using namespace std;

void input()
{
	cin >> N >> M;
	
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			cin >> lab[row][col];

}

void lab_copy()
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			tmp[row][col] = lab[row][col];

}

void BFS()
{
	// Ȯ��� �迭 ����
	int diffusion[MAX][MAX];
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			diffusion[row][col] = tmp[row][col];

	// ���̷��� ��ġ�� ��� ť�� �ִ´�.
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			if (diffusion[row][col] == 2)
				wait_queue.push(pos(row, col));

	// ť�� �� �� ���� �ݺ�
	for (; !wait_queue.empty();)
	{
		int row = wait_queue.front().row;
		int col = wait_queue.front().col;
		wait_queue.pop();

		for (int loop = 0; loop < 4; loop++)
		{
			int next_row = row + move_row[loop];
			int next_col = col + move_col[loop];

			// ���� ��� ���� ���� �̳��̰�
			// Ȯ���� ���� ��� ���� ��ĭ�̸�
			// ���̷����� Ȯ��ȴ�.
			if (0 <= next_row && next_row < N && 0 <= next_col && next_col < M && 
				diffusion[next_row][next_col] == 0)
			{
				diffusion[next_row][next_col] = 2;
				wait_queue.push(pos(next_row, next_col));
			}
		}
	}

	// ���� ���� Ȯ��
	int empty = 0;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			if (diffusion[row][col] == 0)
				empty++;

	// ��
	ans = max(ans, empty);
}

void make_wall(int count)
{
	// ���� 3�� ���������
	// BFS ȣ��, ����
	if (count == 3)
	{
		BFS();
		return;
	}

	// �� �����
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			// �� ���̸�
			// ���� ������, make_wall ���ȣ��
			// ���� �ٽ� �㹮��.
			if (lab[row][col] == 0)
			{
				tmp[row][col] = 1;
				make_wall(count + 1);
				tmp[row][col] = 0;
			}
		}
	}
}

int main()
{
	input();

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			// ������ ��ĭ �߰��ϸ�
			// �������� �ӽù迭�� ����
			// ���� ������, make_wall ȣ��
			// ���� �ٽ� �㹮��.
			if (lab[row][col] == 0)
			{
				lab_copy();

				tmp[row][col] = 1;
				make_wall(1);
				tmp[row][col] = 0;
			}
		}
	}

	cout << ans << endl;
}