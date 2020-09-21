/**
 * @date 20.09.18
 * @brief BOJ 9943
 * @url https://www.acmicpc.net/problem/9943
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define LEFT(node) ((node) * (2))
#define RIGHT(node) ((node) * (2) + (1))

int K;

int* visit_order;		// 방문순서
int visit_index = 1;

int* binary_tree;
int binary_tree_size;

int next_level = 2;

void input_data()
{
	cin >> K;
	binary_tree_size = pow(2, K);

	visit_order = new int[binary_tree_size];
	for (int index = 1; index < binary_tree_size; index++)
		cin >> visit_order[index];
}

void dfs(int node)
{
	if (node >= binary_tree_size)
		return;

	dfs(LEFT(node));

	binary_tree[node] = visit_order[visit_index++];

	dfs(RIGHT(node));
}

void init_binary_tree()
{
	binary_tree = new int[binary_tree_size];

	dfs(1);
}

void print()
{
	for (int node = 1; node < binary_tree_size; node++)
	{
		if (next_level == node)
		{
			cout << endl;
			next_level *= 2;
		}

		cout << binary_tree[node] << " ";
	}
}

int main()
{
	input_data();
	
	init_binary_tree();

	print();
}