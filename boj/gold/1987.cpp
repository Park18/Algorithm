#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int R; // ���� ũ��
int C; // ����ũ��
std::string board[20];		// ����
std::vector<char> record;	// �湮 ���
int ans = 1;

int move_row[]{ -1,1,0,0 };	// ��, ��, ��, ��
int move_col[]{ 0,0,-1,1 }; // ��, ��, ��, ��

using namespace std;

void input()
{
	cin >> R >> C;

	for (int row = 0; row < R; row++)
		cin >> board[row];
}

int DFS(int row, int col)
{
	record.push_back(board[row][col]);
	int count = 0;

	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// �������
		// �湮 ��Ͽ� ���� ������ ���ĺ��� ������
		if (0 <= next_row && next_row < R && 0 <= next_col && next_col < C &&
			find(record.begin(), record.end(), board[next_row][next_col]) == record.end())
		{
			count = max(count, DFS(next_row, next_col));

		}
	}

	record.pop_back();
	return 1 + count;
}

int main()
{
	input();

	cout << DFS(0, 0) << endl;
}