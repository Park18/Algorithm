
#include <iostream>
#include <vector>

int N;								// 노드 개수
std::vector<std::vector<int>> tree; // 링크 트리
bool* visit;						// 방문기록
int* parent;						// 부모노드

using namespace std;

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