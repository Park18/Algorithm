/**
 * @date 20.06.17
 * @brief BOJ 1987
 * @url https://www.acmicpc.net/problem/1987
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int R; // ���� ũ��
int C; // ����ũ��
std::string board[20];		// ����
std::vector<char> record;	// �湮 ���

int move_row[]{ -1,1,0,0 };	// ��, ��, ��, ��
int move_col[]{ 0,0,-1,1 }; // ��, ��, ��, ��

using namespace std;

/**
 * @breif �Է� �޼ҵ�
 */
void input()
{
	cin >> R >> C;

	for (int row = 0; row < R; row++)
		cin >> board[row];
}

/**
 * @brief DFS �޼ҵ�
 * @param int row �湮�� ĭ�� ��
 * @param int col �湮�� ĭ�� ��
 * @return max_visit_size
 * ���� �湮�� ĭ�� �������� �ִ�� �湮�� �� �ִ� �ִ� ũ��
 *
 */
int DFS(int row, int col)
{	
	record.push_back(board[row][col]);	// �湮�� ĭ�� ���ĺ� ���
	int  max_visit_size = 0;						// ���� �湮�� ĭ���� ����

	// ��, ��, ��, �� �˻�
	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// �������
		// �湮 ��Ͽ� ���� ������ ���ĺ��� ������
		// DFS ����, �ִ� �湮 ũ�� ����
		if (0 <= next_row && next_row < R && 0 <= next_col && next_col < C &&
			find(record.begin(), record.end(), board[next_row][next_col]) == record.end())
		{
			 max_visit_size = max(max_visit_size, DFS(next_row, next_col));
		}
	}

	record.pop_back();
	return 1 +  max_visit_size;
}

int main()
{
	input();

	cout << DFS(0, 0) << endl;
}