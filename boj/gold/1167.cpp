/**
 * @date 20.06.22
 * @brief BOJ 1167
 * @url https://www.acmicpc.net/problem/1167
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/**
 * @brief 연결된 노드의 정보
 */
struct node_info
{
	int link_node;	// 연결 노드의 숫자
	int length;		// link_node 까지의 길이
};

int V;										// 노드 개수
std::vector<std::vector<node_info>> tree;	// 트리
bool* visit;								// 방문 기록
int ans = 0;

using namespace std;

/**
 * @brief 입력 메소드
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
 * @brief DFS 메소드
 * @parma int node 방문한 노드
 */
int DFS(int node)
{
	visit[node] = true; // 방문 기록

	int max_lenght = 0; // 현재 노드와 연결된 노드 사이의 최대 거리
	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index).link_node])
		{
			max_lenght = max(max_lenght, tree[node].at(index).length + DFS(tree[node].at(index).link_node));			
		}
	}

	return max_lenght;
}

int main()
{
	input();

	for (int start_node = 1; start_node <= V; start_node++)
	{
		ans = max(ans, DFS(start_node));
		memset(visit, 0, V + 1);
	}

	cout << ans << endl;
}