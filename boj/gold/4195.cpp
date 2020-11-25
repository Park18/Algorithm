/**
 * @url https://www.acmicpc.net/problem/4195
 */

#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Edge_Info
{
public:
	int from;
	int to;

	Edge_Info(int from, int to) :from(from), to(to) {};
};

int test_case;
int F;

map<string, int>node_info;
vector<int>* graph;
bool* visited;

vector<int> result;

int get_result(int parent)
{
	visited[parent] = true;

	if (graph[parent].empty())
		return 1;

	int friend_count = 1;
	for (int children = 0; children < graph[parent].size(); children++)
	{
		if (!visited[graph[parent][children]])
			friend_count += get_result(graph[parent][children]);
	}

	return friend_count;
}

void input_data()
{
	cin >> F;

	graph = new vector<int>[F + 2];
	visited = new bool[F + 1];
	memset(visited, 0, F + 1);

	string a, b;
	int node_count = 1;
	for (int loop = 0; loop < F; loop++)
	{
		cin >> a >> b;

		if (node_info.find(a) == node_info.end())
			node_info.insert(make_pair(a, node_count++));
		if (node_info.find(b) == node_info.end())
			node_info.insert(make_pair(b, node_count++));

		graph[node_info.find(a)->second].push_back(node_info.find(b)->second);
		graph[node_info.find(b)->second].push_back(node_info.find(a)->second);

		result.push_back(get_result(node_info.find(a)->second));

		memset(visited, 0, F + 1);
	}

	delete[] visited;
}

int main()
{
	cin >> test_case;
	for (int loop = 0; loop < test_case; loop++)
	{
		input_data();

		for (auto i : result)
			cout << i << endl;		
	}
}