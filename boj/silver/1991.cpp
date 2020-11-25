/**
 * @date 20.06.09
 * @brief BOJ 1191
 * @url https://www.acmicpc.net/problem/1191
 */

#include <iostream>

#define BASE_SIZE 65	// �θ� �ε��� ����� ���� ��
#define LEFT 0			// ���� �ڽ� �ε���
#define RIGHT 1			// ������ �ڽ� �ε���
#define NO '.'			// �ڽ��� ���� �� ����

int N;				// ��� ����
char** binary_tree;	// ����Ʈ��

using namespace std;

/**
 * @brief binary_tree �迭 �ʱ�ȭ
 */
void init()
{
	binary_tree = new char*[N];

	for (int index = 0; index < N; index++)
		binary_tree[index] = new char[2];
}

/**
 * @brief �Է�
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
 * @brief ���� ��ȸ
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
 * @brief ���� ��ȸ
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
 * @brief ���� ��ȸ
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