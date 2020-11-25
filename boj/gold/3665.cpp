/**
 * @date 20.11.23
 * @url https://www.acmicpc.net/problem/3665
 * @result 
 * @source https://deque.tistory.com/62
 */

#include <iostream>
#include <vector>
#include <queue>

#define UNKOWN "?"
#define IMPOSSIBLE "IMPOSSIBLE"
#define MAX_SIZE 500
#define endl '\n'
using namespace std;

int T, n, m;
int in_degree[MAX_SIZE + 1];			// 진입차수
int graph[MAX_SIZE + 1][MAX_SIZE + 1];	// 위상정렬을 위한 그래프
int ranking[MAX_SIZE + 1];				// 순위
vector<int> result;
bool is_unkown;

void input_data()
{
	cin >> n;
	for (int index = 1; index <= n; index++)
		cin >> ranking[index];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= j; j++)
		{
			graph[ranking[i]][ranking[j]] = 1;
			in_degree[ranking[j]]++;
		}
	}

	cin >> m;
	for (int index = 0; index < m; index++)
	{
		int a, b;
		cin >> a >> b;
		if (graph[a][b])
		{
			graph[a][b] = 0;
			graph[b][a] = 1;
			in_degree[a]++, in_degree[b]--;
		}
		else
		{
			graph[a][b] = 1;
			graph[b][a] = 0;
			in_degree[a]--, in_degree[b]++;
		}

	}
}

void solved()
{
	queue<int> wait_queue;
	for (int index = 1; index <= n; index++)
		if (in_degree[index] == 0)
			wait_queue.push(index);

	is_unkown = false;
	while (!wait_queue.empty())
	{
		if (wait_queue.size() > 1)
		{
			is_unkown = true;
			break;
		}

		int cur = wait_queue.front(); // cur이 뭔뜻임?
		wait_queue.pop();
		result.push_back(cur);

		for (int next = 1; next <= n; next++)
		{
			if (graph[cur][next])
			{
				in_degree[next]--;

				if (in_degree[next] == 0)
					wait_queue.push(next);
			}
		}
	}
}

void print()
{
	if (is_unkown)
		cout << UNKOWN << endl;

	else if (result.size() == n)
		for (auto team : result)
			cout << team << endl;

	else
		cout << IMPOSSIBLE << endl;
}

int main()
{
	cin >> T;

	for (int loop = 0; loop < T; loop++)
	{
		input_data();

		solved();

		print();

		result.clear();
	}
}