/**
 * @brief
 * @url https://www.acmicpc.net/problem/15900
 * @false 메모리 초과
 */

#include <iostream>
#include <cstring>

#define MAX_SIZE 500000

using namespace std;

void init(bool** graph, bool* visit, int size)
{
	memset(visit, 0, size + 1);

	for (int index = 0; index <= size; index++)
	{
		graph[index] = new bool[size + 1];
		memset(graph[index], 0, size + 1);
	}
}

void input_graph(bool** graph, int size)
{
	int a, b;
	for (int loop = 1; loop < size; loop++)
	{
		cin >> a >> b;
		graph[a][b] = graph[b][a] = true;
	}
}

int dfs(bool** graph, int size, int start_node, int level, bool* visit)
{
	visit[start_node] = true;
	
	int total_level = 0;
	for (int node = 1; node <= size; node++)
	{
		if (node == start_node)
			continue;

		if (!visit[node] && graph[start_node][node])
			total_level += dfs(graph, size, node, level + 1, visit);
	}
	
	if(total_level == 0)
		total_level = level;

	return total_level;
}

int main()
{
	int N;
	cin >> N;

	bool** graph = new bool* [N + 1];
	bool* visit = new bool[N + 1];
	init(graph, visit, N);
	input_graph(graph, N);

	cout << (dfs(graph, N, 1, 0, visit) % 2 ? "Yes" : "No" ) << endl;
}