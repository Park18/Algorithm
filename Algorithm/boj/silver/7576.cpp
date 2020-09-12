/**
 * @date 20.06.15
 * @brief BOJ 7576
 * @url https://www.acmicpc.net/problem/7576
 */

#include <iostream>
#include <queue>

/**
 * @brief �ڽ��� ��ġ�� �ð��� �����ϴ� Ŭ����
 */
class pos
{
public:
	int row;	// ��
	int col;	// ��
	int time;	// �ɸ� �ð�

	/**
	 * @brief ������ 
	 */
	pos(int row, int col, int time) :row(row), col(col), time(time) {}
};

int N;		// row_size
int M;		// col_size
int** box;	// �ڽ�
std::queue<pos> wait_queue; // ��� ť

int ans = 0;		// ���
int g_time = 0;		// �ɸ��ð�
int exist = 0;		// ���� �丶�� ����
int non_exist = 0;	// ���� �丶�� ����

int move_row[] = { 0, 0, -1, 1 }; // �� �̵�: ��, ��, ��, ��
int move_col[] = { -1, 1, 0, 0 }; // �� �̵�: ��, ��, ��, ��

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> M >> N;

	box = new int* [N];
	for (int row = 0; row < N; row++)
	{
		box[row] = new int[M];

		for (int col = 0; col < M; col++)
		{
			cin >> box[row][col];

			// �ڽ��� ���� �丶�䰡 ���� �����̸�
			// ���� ���� �丶�� ������ �����ϰ�
			// ��� ť�� �ִ´�.
			if (box[row][col] == 1)
			{
				exist++;
				wait_queue.push(pos(row, col, 0));
			}

			// �ڽ��� �丶�並 ���� ���� ���� ������
			// ���� ���� ������ ���Ž�Ų��.
			else if (box[row][col] == -1)
				non_exist++;
		}
	}
}

/**
 * @brief BFS �޼ҵ�
 */
void BFS()
{
	// ��� ť�� �� ������ �ݺ��Ѵ�.
	for (; !wait_queue.empty();)
	{
		// ��� ť���� row, col�� �޾ƿ��� ����.
		int row = wait_queue.front().row;
		int col = wait_queue.front().col;
		int time = g_time = wait_queue.front().time;
		wait_queue.pop();

		// ������ �丶�並 ã�� ���� �ʾ�����
		// ���� �� ���� �丶�� ������ �����ϰ� ��� ť�� �ִ´�.
		for (int loop = 0; loop < 4; loop++)
		{
			int next_row = row + move_row[loop];
			int next_col = col + move_col[loop];

			if (0 <= next_row && next_row < N && 0 <= next_col && next_col < M &&
				box[next_row][next_col] == 0)
			{
				box[next_row][next_col] = 1;
				exist++;
				wait_queue.push(pos(next_row, next_col, time + 1));
			}
		}

	}
	
	// ��� ť�� �����
	// �ڽ� ũ��� (���� �丶�� + �� ����)�� ������
	// ��� ���� ���̴�.
	if (wait_queue.size() == 0 && M * N == exist + non_exist)
		ans = g_time;

	// ��� ť�� �����
	// �ڽ� ũ�Ⱑ�� (���� �丶�� + �� ����)�� �ٸ���
	// ���� ���� �丶�䰡 �ִ� ���̴�.
	else if (wait_queue.size() == 0 && M * N != exist + non_exist)
		ans = -1;
}

int main()
{
	input();

	// ������ ����
	// �ڽ��� ũ��� ���� �丶�� ���� + ����� �� �Ȱ��ٸ�
	// �̹� �ڽ� ���� �丶�䰡 ���� �����̴�.
	if (M * N == exist + non_exist)
		cout << 0 << endl;

	else
	{
		BFS();
		cout << ans << endl;
	}
}