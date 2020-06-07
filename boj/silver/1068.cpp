/**
  * @date 20.05.17
  * @brief BOJ 1068
  * @url https://www.acmicpc.net/problem/1068
  */

#include <iostream>

using namespace std;

int N;		// ����� ����
int* node;	// �θ� ����� �ε����� ������ �迭�� ������
int delete_index; // ������ ����� �ε���

void input()
{
	cin >> N;

	node = new int[N + 1];
	for (int i = 1; i <= N; i++)
	{
		cin >> node[i];
	}

	cin >> delete_index;
}

int get_count(int parent_index)
{
	// ���� ��� �ε����̸� �� ������ �ڽ� ���� ���� ������
	// ȣ�� ���� �ʰ� 0�� ��ȯ�Ѵ�.
	if (parent_index == delete_index + 1)
		return 0;

	// �ڽ� ����� �ε����� ���� ū ����� �ε������� ũ��
	// ��������̹Ƿ� 1�� ��ȯ�Ѵ�.
	if ((parent_index * 2 > N) && (parent_index * 2 + 1 > N))
		return 1;

	// ���� ��尡 �ƴϸ� ����, ������ �ڽ��� ȣ���� ���� ���Ͽ� ��ȯ�Ѵ�.
	return get_count(parent_index * 2) + get_count(parent_index * 2 + 1);
}

using namespace std;
int main()
{
	input();
	cout << get_count(1) << endl;
}