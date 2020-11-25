/**
 * @date 20.06.12
 * @ BOJ 2667
 * @url https://www.acmicpc.net/problem/2667
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int N;							// ��ũ��
short map[25][25] = { 0 };		// ��
bool visit[25][25] = { false }; // �湮���
std::vector<int> complex_size;	// ������ ũ��
int move_row[] = {0, 0, -1, 1}; // ��, ��, ��, ��
int move_col[] = {-1, 1, 0, 0}; // ��, ��, ��, ��

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;

		for (int i = 0; i < N; i++)
			if (str[i] == '1') map[n][i] = 1;
	}
}

/**
 * @brief DFS �޼ҵ�
 */
void DFS(int row, int col)
{
	visit[row][col] = true;							// �湮 ���
	complex_size.at(complex_size.size() - 1) += 1;	// ���� ���� ����

	// ��, ��, ��, �� �˻�
	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// next_row, col �� ���� ���� �̰� 
		// map[next_row][next_col] = 1 �̰�
		// visit[next_row][next_col]�� �湮���� �ʾ�����
		if (0<=next_row && next_row <N && 0<=next_col && next_col < N &&
			map[next_row][next_col] == 1 && !visit[next_row][next_col])
			DFS(next_row, next_col);
	}
}

int main()
{
	input(); // �Է�

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			// map[row][col] = 1 �̰�
			// visit[row][col]�� �湮���� �ʾ�����
			// ��, ���ο� ������ ã���� ��
			if (map[row][col] == 1 && !visit[row][col])
			{
				complex_size.push_back(0);	// ������ ���� �ʱ�ȭ
				DFS(row, col);				// DFS ȣ��
			}
		}
	}

	// complext_size ������ ��� ���
	sort(complex_size.begin(), complex_size.end());
	cout << complex_size.size() << endl;
	for (int loop = 0; loop < complex_size.size(); loop++)
	{
		cout << complex_size.at(loop) << endl;
	}
}