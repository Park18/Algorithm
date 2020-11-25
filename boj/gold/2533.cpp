/**
 * @url https://www.acmicpc.net/problem/2533
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define YES true
#define NO false

struct EDGE_INFO
{
	int a;
	int b;
};

void input_edge_info(EDGE_INFO* edge_info_group, int size)
{
	for (int loop = 1; loop < size; loop++)
	{
		int a, b;
		cin >> a >> b;

		edge_info_group[loop].a = a;
		edge_info_group[loop].b = b;
	}
}

void init_tree(EDGE_INFO* edge_info_group, vector<int>* tree, int size)
{
	for (int index = 1; index < size; index++)
	{
		 int parent, children;
		 if (edge_info_group[index].a < edge_info_group[index].b)
		 {
		 	parent = edge_info_group[index].a;
		 	children = edge_info_group[index].b;
		 }
		 else
		 {
		 	parent = edge_info_group[index].b;
		 	children = edge_info_group[index].a;
		 }
		 
		 tree[parent].push_back(children);
	}
}

void init_dp(int** dp, int size)
{
	for (int index = 0; index <= size; index++)
		dp[index] = new int[2]{ -1, -1 };

	//memset(dp, -1, sizeof(int) * (size + 1) * 2);
}

int dfs(vector<int>* tree, int** dp, int node, int is_early_adapter)
{
	int& min_result = dp[node][is_early_adapter];
	if (min_result != -1)
		return min_result;

	if (is_early_adapter)
	{
		min_result = 1;
		for (int children = 0; children < tree[node].size(); children++)
			min_result += min(dfs(tree, dp, tree[node][children], YES), dfs(tree, dp, tree[node][children], NO));
	}
	else
	{
		min_result = 0;
		for (int children = 0; children < tree[node].size(); children++)
			min_result += dfs(tree, dp, tree[node][children], YES);
	}

	return min_result;
}

int main()
{
	int N;
	cin >> N;
	
	EDGE_INFO* edge_info_group = new EDGE_INFO[N + 1];
	vector<int>* tree = new vector<int>[N + 1];
	input_edge_info(edge_info_group, N);
	init_tree(edge_info_group, tree, N);
	
	int** dp = new int* [N + 1];
	init_dp(dp, N);
	
	cout << min(dfs(tree, dp, 1, YES), dfs(tree, dp, 1, NO)) << endl;
}