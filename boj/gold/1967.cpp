/**
 * @date 20.06.24
 * @brief BOJ 1967
 * @url https://www.acmicpc.net/problem/1967
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

 /**
  * @brief ����� ����� ����
  */
struct node_info
{
	int link_node;	// ���� ����� ����
	int length;		// link_node ������ ����
};

int V;										// ��� ����
std::vector<std::vector<node_info>> tree;	// Ʈ��
bool* visit;								// �湮 ���
int end_node;								
int ans = 0;								// �ش�

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> V;

	tree.resize(V + 1);
	visit = new bool[V + 1]{ false };

	for (int loop = 0; loop < V-1; loop++)
	{
		int root_node, link_node, lenght;

		cin >> root_node >> link_node >> lenght;
		tree[root_node].push_back({ link_node, lenght });
		tree[link_node].push_back({ root_node, lenght });
	}
}

/**
 * @brief �湮��� �ʱ�ȭ �޼ҵ�
 */
void reset()
{
	for (int loop = 0; loop <= V; loop++)
		visit[loop] = false;
}

/**
 * @brief DFS �޼ҵ�
 * @parma int node �湮�� ���
 * @param int lenght �湮�� ���� ����
 */
void DFS(int node, int lenght)
{
	visit[node] = true; // �湮 ���

	// ���� ���� ����� ��� Ȯ��
	// ���� ����� ��� ��, �湮���� ���� ���� �ִٸ�
	// ���� ����� �ڽ� ��� ���� ����� ������ ��� ��
	// ����� ������ �� ���� �ִ� �������� ũ�ٸ�
	// �ִ� ������ ���� ��������, 
	// ������ ������ ��带 ���� ����� �ڽ� ���� ���� �Ѵ�.
	// �� ��, ���� ����� �ڽ� ��� ������ ������ �ִ��� Ȯ���� ���� DFS(�ڽ� ���) ȣ��
	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index).link_node])
		{
			int link_lenght = lenght + tree[node].at(index).length; // �湮 ����� �ڽ� ������ ����� ����(����ġ)
			if (ans < link_lenght)
			{
				ans = link_lenght;
				end_node = tree[node].at(index).link_node;
			}

			DFS(tree[node].at(index).link_node, link_lenght);
		}
	}
}

int main()
{
	input();
	
	DFS(1, 0);
	reset();
	DFS(end_node, 0);

	cout << ans <<endl;
}