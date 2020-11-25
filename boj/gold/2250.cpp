/**
 * @date 20.06.09
 * @brief BOJ 1191
 * @url https://www.acmicpc.net/problem/1191
 */

#include <iostream>
#include <vector>

#define LEFT 0
#define RIGHT 1
#define NO -2


int N;				// 노드 개수
int** binary_tree;	// 이진트리
bool** table;		// 이진트리 노드 작성 테이블
bool* col_check;	// 열 존재 유무 체크

using namespace std;

void init()
{
	binary_tree = new int* [N];
	table = new bool* [N];
	col_check = new bool[N] {false};

	for (int index = 0; index < N; index++)
	{
		binary_tree[index] = new int[2];
		table[index] = new bool[N] {false};
	}
}

void input()
{
	cin >> N;
	init();

	for (int loop = 0; loop < N; loop++)
	{
		int parent, left, right;
		cin >> parent >> left >> right;

		binary_tree[parent - 1][LEFT] = left - 1;
		binary_tree[parent - 1][RIGHT] = right - 1;
	}
}

void inorder(int node, int level)
{
	if (node == NO)
		return;

	inorder(binary_tree[node][LEFT], level + 1);

	for (int col = 0; col < N; col++)
	{
		if (!col_check[col])
		{
			col_check[col] = true;
			table[level][col] = true;
			break;
		}
	}

	inorder(binary_tree[node][RIGHT], level + 1);
}

void get_result()
{
	vector<int> stack;
	int ans_level = 0;
	int ans_width = 1;

	for (int level = 1; level < N; level++)
	{
		for (int col = 0; col < N; col++)
		{
			if (table[level][col]) stack.push_back(col);
		}

		if (stack.empty()) continue;
		
		if (ans_width < stack.back() - stack.front() + 1)
		{
			ans_level = level;
			ans_width = stack.back() - stack.front() + 1;
		}

		stack.clear();
	}

	cout << ans_level + 1 << " " << ans_width << endl;
}

int main()
{
	input();
	inorder(0, 0);
	get_result();
}