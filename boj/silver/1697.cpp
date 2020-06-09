/**
 * @date 20.06.01
 * @ BOJ 1697
 * @url https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <queue>

#define MAX_SIZE 1000001

using namespace std;

class record
{
public:
	int index;
	int time;

	record(int index, int time) :index(index), time(time) {}
};

int main()
{
	// 입력
	int N; // 수빈
	int K; // 동생
	cin >> N >> K;

	// 방문기록, 큐, 시간 초기화
	bool line[MAX_SIZE] = { false };
	line[N] = true;

	queue<record> wait_queue;
	wait_queue.push(record(N, 0));

	// BFS
	for (; !wait_queue.empty();)
	{
		int index = wait_queue.front().index;
		int time = wait_queue.front().time;
		wait_queue.pop();

		// 방문한 인덱스가 K일 때
		// 시간을 출력하고 종료
		if (index == K)
		{
			cout << time << endl;
			return 0;
		}

		// 세 가지 방법
		// 걷기: ±1
		// 순간이동: ×2
		// 이미 방문한 경우 큐에 넣지 않는다.
		if (0 <= index - 1 && !line[index - 1])
		{
			wait_queue.push(record(index - 1, time + 1));
			line[index - 1] = true;
		}

		if (index + 1 < MAX_SIZE && !line[index + 1])
		{
			wait_queue.push(record(index + 1, time + 1));
			line[index + 1] = true;
		}

		if (index * 2 < MAX_SIZE && !line[index * 2])
		{
			wait_queue.push(record(index * 2, time + 1));
			line[index * 2] = true;
		}
	}
}