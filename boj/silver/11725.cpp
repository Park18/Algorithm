/**
 * @date 20.06.21
 * @brief BOJ 11725
 * @url https://www.acmicpc.net/problem/11725
 */

#include <iostream>
#include <vector>

int N;								// ��� ����
std::vector<std::vector<int>> tree; // ��ũ Ʈ��
bool* visit;						// �湮���
int* parent;						// �θ���

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> N;

	tree.resize(N + 1);
	visit = new bool[N + 1]{ false };
	parent = new int[N + 1]{ 0 };

	for (int loop = 1; loop < N; loop++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
}

/**
 * @brief DFS �޼ҵ�
 * @detil DFS�� �湮�Ͽ� �θ� ���
 */
void DFS(int node)
{
	visit[node] = true;

	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index)])
		{
			parent[tree[node].at(index)] = node;
			DFS(tree[node].at(index));
		}
	}
}

int main()
{
	input();

	DFS(1);

	for (int index = 2; index <= N; index++)
		cout << parent[index] << '\n';
}