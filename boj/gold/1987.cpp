/**
 * @date 20.06.17
 * @brief BOJ 1987
 * @url https://www.acmicpc.net/problem/1987
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int R; // 세로 크기
int C; // 가로크기
std::string board[20];		// 보드
std::vector<char> record;	// 방문 기록

int move_row[]{ -1,1,0,0 };	// 상, 하, 좌, 우
int move_col[]{ 0,0,-1,1 }; // 상, 하, 좌, 우

using namespace std;

/**
 * @breif 입력 메소드
 */
void input()
{
	cin >> R >> C;

	for (int row = 0; row < R; row++)
		cin >> board[row];
}

/**
 * @brief DFS 메소드
 * @param int row 방문한 칸의 행
 * @param int col 방문한 칸의 열
 * @return max_visit_size
 * 현재 방문한 칸을 시작으로 최대로 방문할 수 있는 최대 크기
 *
 */
int DFS(int row, int col)
{	
	record.push_back(board[row][col]);	// 방문한 칸의 알파벳 기록
	int  max_visit_size = 0;						// 이후 방문할 칸들의 개수

	// 상, 하, 좌, 우 검색
	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// 정상범위
		// 방문 기록에 다음 보드의 알파벳이 없으면
		// DFS 실행, 최대 방문 크기 설정
		if (0 <= next_row && next_row < R && 0 <= next_col && next_col < C &&
			find(record.begin(), record.end(), board[next_row][next_col]) == record.end())
		{
			 max_visit_size = max(max_visit_size, DFS(next_row, next_col));
		}
	}

	record.pop_back();
	return 1 +  max_visit_size;
}

int main()
{
	input();

	cout << DFS(0, 0) << endl;
}