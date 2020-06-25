
#include <iostream>
#include <cstring>
#include <vector>

int N;								// 정점의 개수
int M;								// 알고 싶은 정점 쌍의 개수
std::vector<std::vector<int>> tree;	// 트리
bool* visit;						// 방문기록
std::vector<int> line1;
std::vector<int> line2;
std::vector<int> result;

using namespace std;

void input()
{
	cin >> N;

	tree.resize(N + 1);
	visit = new bool[N + 1]{ false };

	for (int loop = 0; loop < N - 1; loop++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	cin >> M;
}

bool DFS(int node, int find_node, vector<int>& line)
{
	line.push_back(node);
	visit[node] = true;
	
	if (node == find_node)
		return true;

	for (int index = 0; index < tree[node].size(); index++)
	{
		if (!visit[tree[node].at(index)])
		{
			if (DFS(tree[node].at(index), find_node, line))
				return true;
		}
	}
	
	line.pop_back();
	return false;
}

void reset()
{
	for (int index = 0; index < N + 1; index++)
	{
		visit[index] = false;
	}
}

int get_result()
{
	for (int line1_index = line1.size() - 1; line1_index >= 0; line1_index--)
	{
		for (int line2_index = line2.size() - 1; line2_index >= 0; line2_index--)
		{
			if (line1[line1_index] == line2[line2_index])
			{
				return line2[line2_index];
			}
		}
	}
}

int solution()
{
	for (int loop = 0; loop < M; loop++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		DFS(1, node1, line1);
		reset();
		DFS(1, node2, line2);
		reset();

		result.push_back(get_result());

		line1.clear();
		line2.clear();
	}
	return 0;
}

int main()
{
	input();

	solution();

	for (int ans : result)
		cout << ans << endl;
}