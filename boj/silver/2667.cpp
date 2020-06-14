/**
 * @date 20.06.12
 * @ BOJ 2667
 * @url https://www.acmicpc.net/problem/2667
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int N;							// 맵크기
short map[25][25] = { 0 };		// 맵
bool visit[25][25] = { false }; // 방문기록
std::vector<int> complex_size;	// 단지별 크기
int move_row[] = {0, 0, -1, 1}; // 상, 하, 좌, 우
int move_col[] = {-1, 1, 0, 0}; // 상, 하, 좌, 우

using namespace std;

/**
 * @brief 입력 메소드
 */
void input()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		string str;
		cin >> str;

		for (int i = 0; i < N; i++)
			if (str[i] == '1') map[n][i] = 1;
	}
}

/**
 * @brief DFS 메소드
 */
void DFS(int row, int col)
{
	visit[row][col] = true;							// 방문 기록
	complex_size.at(complex_size.size() - 1) += 1;	// 단지 개수 증가

	// 상, 하, 좌, 우 검사
	for (int loop = 0; loop < 4; loop++)
	{
		int next_row = row + move_row[loop];
		int next_col = col + move_col[loop];

		// next_row, col 이 정상 범위 이고 
		// map[next_row][next_col] = 1 이고
		// visit[next_row][next_col]에 방문하지 않았으면
		if (0<=next_row && next_row <N && 0<=next_col && next_col < N &&
			map[next_row][next_col] == 1 && !visit[next_row][next_col])
			DFS(next_row, next_col);
	}
}

int main()
{
	input(); // 입력

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			// map[row][col] = 1 이고
			// visit[row][col]에 방문하지 않았으면
			// 즉, 새로운 단지를 찾았을 때
			if (map[row][col] == 1 && !visit[row][col])
			{
				complex_size.push_back(0);	// 단지의 개수 초기화
				DFS(row, col);				// DFS 호출
			}
		}
	}

	// complext_size 정렬후 결과 출력
	sort(complex_size.begin(), complex_size.end());
	cout << complex_size.size() << endl;
	for (int loop = 0; loop < complex_size.size(); loop++)
	{
		cout << complex_size.at(loop) << endl;
	}
}