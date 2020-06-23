/**
 * @date 20.06.22
 * @brief BOJ 1167
 * @url https://www.acmicpc.net/problem/1167
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
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
int ans = 0;

using namespace std;

/**
 * @brief �Է� �޼ҵ�
 */
void input()
{
	cin >> V;

	tree.resize(V + 1);
	visit = new bool[V + 1]{ false };

	for (int loop = 0; loop < V; loop++)
	{
		int root_node;
		cin >> root_node;

		for (;;)
		{
			int link_node, lenght;
			cin >> link_node;
			if (link_node == -1)
				break;

			cin >> lenght;


			tree[root_node].push_back({ link_node, lenght });
		}
	}
}

/**
 * @brief DFS �޼ҵ�
 * @parma int node �湮�� ���
 */
int DFS(int node)
{
	visit[node] = true; // �湮 ���

	int max_lenght = 0; // ���� ���� ����� ��� ������ �ִ� �Ÿ�
	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index).link_node])
		{
			max_lenght = max(max_lenght, tree[node].at(index).length + DFS(tree[node].at(index).link_node));			
		}
	}

	return max_lenght;
}

void BFS(int start_node)
{
	visit[start_node] = true;
	queue<pair<node_info, int>> wait_queue;
	for (int index = 0; index < tree[start_node].size(); index++)
		wait_queue.push({ tree[start_node].at(index), 0 });

	for (; !wait_queue.empty();)
	{
		int node = wait_queue.front().first.link_node; // ����� ���
		int lenght = wait_queue.front().first.length + wait_queue.front().second;	// ����� ��� ������ ����
		wait_queue.pop();

		visit[node] = true;
		ans = max(ans, lenght);

		for (int index = 0; index < tree[node].size(); index++)
		{
			if (!visit[tree[node].at(index).link_node])
				wait_queue.push({ tree[node].at(index), lenght });
		}
	}
}

int main()
{
	input();

	for (int start_node = 1; start_node <= V; start_node++)
	{
		//ans = max(ans, DFS(start_node));
		BFS(start_node);
		memset(visit, 0, V + 1);
	}

	cout << ans << '\n';
}