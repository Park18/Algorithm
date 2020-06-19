/**
 * @date 20.06.09
 * @brief BOJ 1191
 * @url https://www.acmicpc.net/problem/1191
 */

#include <iostream>

#define BASE_SIZE 65	// 부모 인덱스 계산을 위한 값
#define LEFT 0			// 왼쪽 자식 인덱스
#define RIGHT 1			// 오른쪽 자식 인덱스
#define NO '.'			// 자식이 없을 때 문자

int N;				// 노드 개수
char** binary_tree;	// 이진트리

using namespace std;

/**
 * @brief binary_tree 배열 초기화
 */
void init()
{
	binary_tree = new char*[N];

	for (int index = 0; index < N; index++)
		binary_tree[index] = new char[2];
}

/**
 * @brief 입력
 */
void input()
{
	cin >> N;

	init();

	for (int loop = 0; loop < N; loop++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		binary_tree[parent - BASE_SIZE][LEFT] = left;
		binary_tree[parent - BASE_SIZE][RIGHT] = right;
	}
}

/**
 * @brief 전위 순회
 */
void preorder(char node)
{
	if (node == NO)
		return;

	cout << node;
	preorder(binary_tree[node - BASE_SIZE][LEFT]);
	preorder(binary_tree[node - BASE_SIZE][RIGHT]);
}

/**
 * @brief 중위 순회
 */
void inorder(char node)
{
	if (node == NO)
		return;

	inorder(binary_tree[node - BASE_SIZE][LEFT]);
	cout << node;
	inorder(binary_tree[node - BASE_SIZE][RIGHT]);
}

/**
 * @brief 후위 순회
 */
void postorder(char node)
{
	if (node == NO)
		return;

	postorder(binary_tree[node - BASE_SIZE][LEFT]);
	postorder(binary_tree[node - BASE_SIZE][RIGHT]);
	cout << node;
}

int main()
{
	input();

	preorder('A'); cout << endl;
	inorder('A'); cout << endl;
	postorder('A'); cout << endl;
}