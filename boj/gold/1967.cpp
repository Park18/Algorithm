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
int end_node;								
int ans = 0;								// 해답

using namespace std;

/**
 * @brief 입력 메소드
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

	//for (int node = 1; node < V; node++)
	//{
	//	for (int col = 0; col < tree[node].size(); col++)
	//	{
	//		cout << tree[node].at(col).link_node << " ";
	//	}
	//
	//	cout << endl;
	//}
}

void reset()
{
	for (int loop = 0; loop <= V; loop++)
		visit[loop] = false;
}

/**
 * @brief DFS 메소드
 * @parma int node 방문한 노드
 * @param int lenght 방문할 때의 지름
 */
void DFS(int node, int lenght)
{
	visit[node] = true; // 방문 기록

	int max_lenght = 0; // 현재 노드와 연결된 노드 사이의 최대 거리
	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index).link_node])
		{
			int link_lenght = lenght + tree[node].at(index).length;
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
	cout << ans << " " << end_node << endl;
}