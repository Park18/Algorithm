/**
 * @date 20.06.10
 * @ BOJ 2486
 * @url https://www.acmicpc.net/problem/2486
 */
#include <iostream>
#include <algorithm>

int N;
int map[100][100] = { 0 };
bool visit[100][100] = { false };

// ��, �Ʒ�, ������, ����
int move_row[4] = {-1, +1, 0, 0};
int move_col[4] = {0, 0, +1, -1};

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> N;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			cin >> map[row][col];
}

/**
 * @brief �湮 ��� �ʱ�ȭ �޼ҵ�
 */
void clear()
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			visit[row][col] = false;
}

/**
 * @brief DFS �޼ҵ�
 */
void DFS(int row, int col, int water_size)
{
	//�湮 ���
	visit[row][col] = true;

	// ��, ��, �¿�
	for (int loop = 0; loop < 4; loop++)
	{
		// ���� ��, �� �ʱ�ȭ
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// ���� ��, ���� ���� �����̰� �湮���� �ʾ����� ���̰� ���� ���̺��� ������
		// ���� ��, �� ��ġ�� �̵��Ѵ�.(DFS)
		if (0 <= next_row && next_row < N && 0 <= next_col && next_col < N && 
			!visit[next_row][next_col] && water_size < map[next_row][next_col])
		{
			DFS(next_row, next_col, water_size);
		}
	}
}

int main()
{
	input();

	// ���� 0�� �� ��������� �� ��ü ��, 1���̹Ƿ�
	// �� ó�� �ִ� ũ��� 1�̴�.
	//
	// ���� ���̰� 0 ~ 100������ ������ �������� ������ �����Ѵ�.
	int max_size = 1;
	for (int water_size = 0; water_size <= 100; water_size++)
	{
		int count = 0; // ���� ���̰� n�� ���� �������� ����
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
			{
				// �ش� ��, ���� �湮���� �ʾ����� ���� ���̺��� ���� ���
				// �湮�� �� �������븦 1�� ������Ų��.
				if (!visit[row][col] && water_size < map[row][col])
				{
					DFS(row, col, water_size);
					count++;
				}
			}
		}
		
		max_size = max(max_size, count); // �ִ� ũ�� ����
		clear(); // �湮��� �ʱ�ȭ
	}

	// ��� ���
	cout << max_size << endl;
}