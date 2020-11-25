/**
  * @date 20.05.17
  * @brief BOJ 1068
  * @url https://www.acmicpc.net/problem/1068
  */

#include <iostream>

using namespace std;

int N;		// 노드의 개수
int* node;	// 부모 노드의 인덱스를 저장할 배열의 포인터
int delete_index; // 삭제할 노드의 인덱스

void input()
{
	cin >> N;

	node = new int[N + 1];
	for (int i = 1; i <= N; i++)
	{
		cin >> node[i];
	}

	cin >> delete_index;
}

int get_count(int parent_index)
{
	// 삭제 노드 인덱스이면 그 이후의 자식 노드는 없기 때문에
	// 호출 하지 않고 0을 반환한다.
	if (parent_index == delete_index + 1)
		return 0;

	// 자식 노드이 인덱스가 가장 큰 노드의 인덱스보다 크면
	// 리프노드이므로 1을 반환한다.
	if ((parent_index * 2 > N) && (parent_index * 2 + 1 > N))
		return 1;

	// 리프 노드가 아니면 왼쪽, 오른족 자식의 호출한 값을 더하여 반환한다.
	return get_count(parent_index * 2) + get_count(parent_index * 2 + 1);
}

using namespace std;
int main()
{
	input();
	cout << get_count(1) << endl;
}