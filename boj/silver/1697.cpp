/**
 * @date 20.06.01
 * @ BOJ 1697
 * @url https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <queue>

#define MAX_SIZE 1000001

using namespace std;

class record
{
public:
	int index;
	int time;

	record(int index, int time) :index(index), time(time) {}
};

int main()
{
	// �Է�
	int N; // ����
	int K; // ����
	cin >> N >> K;

	// �湮���, ť, �ð� �ʱ�ȭ
	bool line[MAX_SIZE] = { false };
	line[N] = true;

	queue<record> wait_queue;
	wait_queue.push(record(N, 0));

	// BFS
	for (; !wait_queue.empty();)
	{
		int index = wait_queue.front().index;
		int time = wait_queue.front().time;
		wait_queue.pop();

		// �湮�� �ε����� K�� ��
		// �ð��� ����ϰ� ����
		if (index == K)
		{
			cout << time << endl;
			return 0;
		}

		// �� ���� ���
		// �ȱ�: ��1
		// �����̵�: ��2
		// �̹� �湮�� ��� ť�� ���� �ʴ´�.
		if (0 <= index - 1 && !line[index - 1])
		{
			wait_queue.push(record(index - 1, time + 1));
			line[index - 1] = true;
		}

		if (index + 1 < MAX_SIZE && !line[index + 1])
		{
			wait_queue.push(record(index + 1, time + 1));
			line[index + 1] = true;
		}

		if (index * 2 < MAX_SIZE && !line[index * 2])
		{
			wait_queue.push(record(index * 2, time + 1));
			line[index * 2] = true;
		}
	}
}