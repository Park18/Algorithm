/**
 * @date 20.09.20
 * @url https://www.acmicpc.net/problem/1922
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Link_Info
{
public:
	int from;
	int to;
	int cost;

	Link_Info(int from, int to, int cost) :from(from), to(to), cost(cost) {};

	bool operator<(Link_Info& link_info)
	{
		return this->cost < link_info.cost;
	}
};

int get_parent(int parent[], int node)
{
	if (parent[node] == node)
		return node;

	return get_parent(parent, parent[node]);
}

void union_parent(int parent[], int a, int b)
{
	a = get_parent(parent, a);
	b = get_parent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool equal_parent(int parent[], int a, int b)
{
	a = get_parent(parent, a);
	b = get_parent(parent, b);

	if (a == b)
		return true;

	return false;
}

void input_data(int& N, int& M, vector<Link_Info>& link_info_group)
{
	cin >> N >> M;

	for (int loop = 0; loop < M; loop++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		link_info_group.push_back(Link_Info(from, to, cost));
	}
}

void init(int* parent, int size)
{
	for (int index = 0; index <= size; index++)
		parent[index] = index;
}

void ascending_sort(vector<Link_Info>& link_info_group)
{
	sort(link_info_group.begin(), link_info_group.end());
}

int get_result(vector<Link_Info> link_info_group, int* parent)
{
	int total_cost = 0;
	for (int index = 0; index < link_info_group.size(); index++)
	{
		if (!equal_parent(parent, link_info_group[index].from, link_info_group[index].to))
		{
			total_cost += link_info_group[index].cost;

			union_parent(parent, link_info_group[index].from, link_info_group[index].to);
		}
	}

	return total_cost;
}

int main()
{
	int N, M;
	vector<Link_Info> link_info_group;
	input_data(N, M, link_info_group);

	int* parent = new int[N + 1];
	init(parent, N);

	ascending_sort(link_info_group);
	cout << get_result(link_info_group, parent) << endl;
}