/**
 * @date 20.09.26
 * @url https://www.acmicpc.net/problem/14621
 * @ 틀림
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MALE true
#define FEMALE false

struct NODE
{
	bool sex;
};

struct EDGE_INFO
{
	int a;
	int b;
	int cost;

	bool operator<(EDGE_INFO& edge_info)
	{
		return this->cost < edge_info.cost;
	}
};

#define N_MAX 1000
#define M_MAX 10000

int N, M;
NODE graph[N_MAX + 1];
EDGE_INFO edge_info_group[M_MAX];
int parent[N_MAX + 1];

int get_parent(int node)
{
	if (parent[node] == node)
		return node;

	return get_parent(parent[node]);
}

void union_parent(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool equal_parent(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);

	if (a == b)
		return true;

	return false;
}

void input_data()
{
	cin >> N >> M;
	for (int index = 1; index <= N; index++)
	{
		char sex;
		cin >> sex;
		
		graph[index].sex = sex == 'M' ? MALE : FEMALE;
	}

	for (int index = 0; index < M; index++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge_info_group[index].a = a;
		edge_info_group[index].b = b;
		edge_info_group[index].cost = cost;
	}
}

int get_result()
{
	int total_cost = 0;
	for (int index = 0; index < M; index++)
	{
		int a = edge_info_group[index].a;
		int b = edge_info_group[index].b;
		if (!equal_parent(a, b) && graph[a].sex != graph[b].sex)
		{
			total_cost += edge_info_group[index].cost;

			union_parent(a, b);
		}
	}

	if (total_cost == 0)
		total_cost = -1;

	return total_cost;
}

int main()
{
	input_data();

	// union-find, 부모 배열 초기화
	for (int index = 0; index <= N; index++)
		parent[index] = index;

	sort(edge_info_group, edge_info_group + M);
	cout << get_result() << endl;
}
