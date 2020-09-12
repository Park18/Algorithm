/**
 * @date 20.06.13
 * @ BOJ 2606
 * @url https://www.acmicpc.net/problem/2606
 */

#include <iostream>

int N = 0;							// 컴퓨터의 수
int network_size = 0;				// 너트워크상 연결된 컴퓨터 쌍 개수
bool network[100][100] = { false }; // 네트워크 그래프
bool visit[100] = { false };		// 방문기록
int count;							// 감염 개수

using namespace std;

/**
 * @brief 입력 메소드
 */
void input()
{
	cin >> N;
	cin >> network_size;

	for (int loop = 0; loop < network_size; loop++)
	{
		int from, to;
		cin >> from >> to;

		from--;
		to--;

		network[from][to] = network[to][from] = true;
	}
}

/**
 * @brief DFS 메소드
 * @param int row 방문할 컴퓨터에 해당하는 행
 */
void DFS(int row)
{
	visit[row] = true; // 방문 기록

	for (int col = 0; col < N; col++)
	{
		// network가 연결되어있고 
		// 컴퓨터[col]에 방문하지 않았다면 
		if (network[row][col] && !visit[col])
		{
			DFS(col);
			::count++;
		}
	}
}

int main()
{
	input();

	DFS(0);
	
	cout << ::count << endl;
}