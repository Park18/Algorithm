/**
 * @date 20.06.13
 * @ BOJ 2606
 * @url https://www.acmicpc.net/problem/2606
 */

#include <iostream>

int N = 0;							// ��ǻ���� ��
int network_size = 0;				// ��Ʈ��ũ�� ����� ��ǻ�� �� ����
bool network[100][100] = { false }; // ��Ʈ��ũ �׷���
bool visit[100] = { false };		// �湮���
int count;							// ���� ����

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> N;
	cin >> network_size;

	for (int loop = 0; loop < network_size; loop++)
	{
		int from, to;
		cin >> from >> to;

		from--;
		to--;

		network[from][to] = network[to][from] = true;
	}
}

/**
 * @brief DFS �޼ҵ�
 * @param int row �湮�� ��ǻ�Ϳ� �ش��ϴ� ��
 */
void DFS(int row)
{
	visit[row] = true; // �湮 ���

	for (int col = 0; col < N; col++)
	{
		// network�� ����Ǿ��ְ� 
		// ��ǻ��[col]�� �湮���� �ʾҴٸ� 
		if (network[row][col] && !visit[col])
		{
			DFS(col);
			::count++;
		}
	}
}

int main()
{
	input();

	DFS(0);
	
	cout << ::count << endl;
}