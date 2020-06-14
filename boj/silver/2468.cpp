/**
 * @date 20.06.10
 * @ BOJ 2486
 * @url https://www.acmicpc.net/problem/2486
 */
#include <iostream>
#include <algorithm>

int N;
int map[100][100] = { 0 };
bool visit[100][100] = { false };

// 위, 아래, 오른쪽, 왼쪽
int move_row[4] = {-1, +1, 0, 0};
int move_col[4] = {0, 0, +1, -1};

using namespace std;

/**
 * @brief 입력 메소드
 */
void input()
{
	cin >> N;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			cin >> map[row][col];
}

/**
 * @brief 방문 기록 초기화 메소드
 */
void clear()
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			visit[row][col] = false;
}

/**
 * @brief DFS 메소드
 */
void DFS(int row, int col, int water_size)
{
	//방문 기록
	visit[row][col] = true;

	// 상, 하, 좌우
	for (int loop = 0; loop < 4; loop++)
	{
		// 다음 행, 열 초기화
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// 다음 행, 열이 정상 범위이고 방문하지 않았으며 높이가 물의 깊이보다 낮으면
		// 다음 행, 열 위치로 이동한다.(DFS)
		if (0 <= next_row && next_row < N && 0 <= next_col && next_col < N && 
			!visit[next_row][next_col] && water_size < map[next_row][next_col])
		{
			DFS(next_row, next_col, water_size);
		}
	}
}

int main()
{
	input();

	// 물이 0일 때 안전지대는 맵 전체 즉, 1개이므로
	// 맨 처음 최대 크기는 1이다.
	//
	// 물의 깊이가 0 ~ 100까지의 각각의 안전지대 개수를 조사한다.
	int max_size = 1;
	for (int water_size = 0; water_size <= 100; water_size++)
	{
		int count = 0; // 물의 깊이가 n일 때의 안전지대 개수
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
			{
				// 해당 행, 열을 방문하지 않았으며 물의 깊이보다 높은 경우
				// 방문한 후 안전지대를 1개 증가시킨다.
				if (!visit[row][col] && water_size < map[row][col])
				{
					DFS(row, col, water_size);
					count++;
				}
			}
		}
		
		max_size = max(max_size, count); // 최대 크기 갱신
		clear(); // 방문기록 초기화
	}

	// 결과 출력
	cout << max_size << endl;
}