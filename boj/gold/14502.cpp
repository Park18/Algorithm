/**
 * @date 20.06.15
 * @brief BOJ 14502
 * @url https://www.acmicpc.net/problem/14502
 */

#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 8

class pos
{
public:
	int row;
	int col;

	pos(int row, int col) :row(row), col(col) {}
};

int N;				// row_size
int M;				// col_size
int lab[MAX][MAX];	// 연구소
int tmp[MAX][MAX];	// 연구소 복사본
int ans;			// 결과

std::queue<pos> wait_queue; // 대기 큐

int move_row[] = { 0, 0, -1, 1 }; // 상, 하, 좌, 우
int move_col[] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우

using namespace std;

void input()
{
	cin >> N >> M;
	
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			cin >> lab[row][col];

}

void lab_copy()
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			tmp[row][col] = lab[row][col];

}

void BFS()
{
	// 확산용 배열 생성
	int diffusion[MAX][MAX];
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			diffusion[row][col] = tmp[row][col];

	// 바이러스 위치를 대기 큐에 넣는다.
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			if (diffusion[row][col] == 2)
				wait_queue.push(pos(row, col));

	// 큐가 빌 때 까지 반복
	for (; !wait_queue.empty();)
	{
		int row = wait_queue.front().row;
		int col = wait_queue.front().col;
		wait_queue.pop();

		for (int loop = 0; loop < 4; loop++)
		{
			int next_row = row + move_row[loop];
			int next_col = col + move_col[loop];

			// 다음 행과 열이 범위 이내이고
			// 확산의 다음 행과 열이 빈칸이면
			// 바이러스가 확산된다.
			if (0 <= next_row && next_row < N && 0 <= next_col && next_col < M && 
				diffusion[next_row][next_col] == 0)
			{
				diffusion[next_row][next_col] = 2;
				wait_queue.push(pos(next_row, next_col));
			}
		}
	}

	// 안전 영역 확인
	int empty = 0;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < M; col++)
			if (diffusion[row][col] == 0)
				empty++;

	// 비교
	ans = max(ans, empty);
}

void make_wall(int count)
{
	// 벽을 3개 만들었으면
	// BFS 호출, 종료
	if (count == 3)
	{
		BFS();
		return;
	}

	// 벽 만들기
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			// 빈 곳이면
			// 벽을 생성후, make_wall 재귀호출
			// 벽을 다시 허문다.
			if (lab[row][col] == 0)
			{
				tmp[row][col] = 1;
				make_wall(count + 1);
				tmp[row][col] = 0;
			}
		}
	}
}

int main()
{
	input();

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			// 연구실 빈칸 발견하면
			// 연구실을 임시배열에 복사
			// 벽을 생성후, make_wall 호출
			// 벽을 다시 허문다.
			if (lab[row][col] == 0)
			{
				lab_copy();

				tmp[row][col] = 1;
				make_wall(1);
				tmp[row][col] = 0;
			}
		}
	}

	cout << ans << endl;
}