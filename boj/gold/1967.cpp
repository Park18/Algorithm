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
}

/**
 * @brief 방문기록 초기화 메소드
 */
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

	// 현재 노드와 연결된 노드 확인
	// 만약 연결된 노드 중, 방문하지 않은 곳이 있다면
	// 현재 노드의 자식 노드 까지 연결된 지름을 계산 후
	// 연산된 지름이 그 전에 최대 지름보다 크다면
	// 최대 지름을 현재 지름으로, 
	// 지름의 마지막 노드를 현재 노드의 자식 노드로 변경 한다.
	// 그 후, 현재 노드의 자식 노드 이후의 지름이 있는지 확인을 위해 DFS(자식 노드) 호출
	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index).link_node])
		{
			int link_lenght = lenght + tree[node].at(index).length; // 방문 노드의 자식 노드까지 연결된 지름(가중치)
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