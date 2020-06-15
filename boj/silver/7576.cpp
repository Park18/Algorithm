/**
 * @date 20.06.15
 * @brief BOJ 7576
 * @url https://www.acmicpc.net/problem/7576
 */

#include <iostream>
#include <queue>

/**
 * @brief 박스의 위치와 시간을 관리하는 클래스
 */
class pos
{
public:
	int row;	// 행
	int col;	// 열
	int time;	// 걸린 시간

	/**
	 * @brief 생성자 
	 */
	pos(int row, int col, int time) :row(row), col(col), time(time) {}
};

int N;		// row_size
int M;		// col_size
int** box;	// 박스
std::queue<pos> wait_queue; // 대기 큐

int ans = 0;		// 결과
int g_time = 0;		// 걸린시간
int exist = 0;		// 익은 토마토 개수
int non_exist = 0;	// 없는 토마토 개수

int move_row[] = { 0, 0, -1, 1 }; // 행 이동: 상, 하, 좌, 우
int move_col[] = { -1, 1, 0, 0 }; // 열 이동: 상, 하, 좌, 우

using namespace std;

/**
 * @brief 입력 메소드
 */
void input()
{
	cin >> M >> N;

	box = new int* [N];
	for (int row = 0; row < N; row++)
	{
		box[row] = new int[M];

		for (int col = 0; col < M; col++)
		{
			cin >> box[row][col];

			// 박스에 넣은 토마토가 익은 상태이면
			// 익은 상태 토마토 개수를 갱신하고
			// 대기 큐에 넣는다.
			if (box[row][col] == 1)
			{
				exist++;
				wait_queue.push(pos(row, col, 0));
			}

			// 박스에 토마토를 넣지 않은 곳이 있으면
			// 넣지 않은 개수를 갱신시킨다.
			else if (box[row][col] == -1)
				non_exist++;
		}
	}
}

/**
 * @brief BFS 메소드
 */
void BFS()
{
	// 대기 큐가 빌 때까지 반복한다.
	for (; !wait_queue.empty();)
	{
		// 대기 큐에서 row, col를 받아오고 뺀다.
		int row = wait_queue.front().row;
		int col = wait_queue.front().col;
		int time = g_time = wait_queue.front().time;
		wait_queue.pop();

		// 인접한 토마토를 찾아 익지 않았으면
		// 익힌 후 익힌 토마토 개수를 갱신하고 대기 큐에 넣는다.
		for (int loop = 0; loop < 4; loop++)
		{
			int next_row = row + move_row[loop];
			int next_col = col + move_col[loop];

			if (0 <= next_row && next_row < N && 0 <= next_col && next_col < M &&
				box[next_row][next_col] == 0)
			{
				box[next_row][next_col] = 1;
				exist++;
				wait_queue.push(pos(next_row, next_col, time + 1));
			}
		}

	}
	
	// 대기 큐가 비었고
	// 박스 크기와 (익은 토마토 + 빈 공간)가 같으면
	// 모두 익은 것이다.
	if (wait_queue.size() == 0 && M * N == exist + non_exist)
		ans = g_time;

	// 대기 큐가 비었고
	// 박스 크기가와 (익은 토마토 + 빈 공간)가 다르면
	// 익지 않은 토마토가 있는 것이다.
	else if (wait_queue.size() == 0 && M * N != exist + non_exist)
		ans = -1;
}

int main()
{
	input();

	// 익히기 전에
	// 박스의 크기와 익은 토마토 개수 + 빈공간 와 똑같다면
	// 이미 박스 안의 토마토가 익은 상태이다.
	if (M * N == exist + non_exist)
		cout << 0 << endl;

	else
	{
		BFS();
		cout << ans << endl;
	}
}