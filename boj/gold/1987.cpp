#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int R; // 세로 크기
int C; // 가로크기
std::string board[20];		// 보드
std::vector<char> record;	// 방문 기록
int ans = 1;

int move_row[]{ -1,1,0,0 };	// 상, 하, 좌, 우
int move_col[]{ 0,0,-1,1 }; // 상, 하, 좌, 우

using namespace std;

void input()
{
	cin >> R >> C;

	for (int row = 0; row < R; row++)
		cin >> board[row];
}

int DFS(int row, int col)
{
	record.push_back(board[row][col]);
	int count = 0;

	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// 정상범위
		// 방문 기록에 다음 보드의 알파벳이 없으면
		if (0 <= next_row && next_row < R && 0 <= next_col && next_col < C &&
			find(record.begin(), record.end(), board[next_row][next_col]) == record.end())
		{
			count = max(count, DFS(next_row, next_col));

		}
	}

	record.pop_back();
	return 1 + count;
}

int main()
{
	input();

	cout << DFS(0, 0) << endl;
}