/**
 * @date 20.11.09
 * @url https://www.acmicpc.net/problem/1931
 * @result ½ÇÆÐ
 */

// 3
// 1 6
// 5 8
// 7 12

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct time_info
{
	int start;
	int end;

	time_info(int start, int end) : start(start), end(end) {};
};

int N;
int result = 0;
vector<time_info> time_info_group;

void input_data()
{
	cin >> N;
	for (int loop = 0; loop < N; loop++)
	{
		int start, end;
		cin >> start >> end;
		time_info_group.push_back(time_info(start, end));
	}
}

bool compare(time_info a, time_info b)
{
	return a.end < b.end;
}

void solved()
{
	sort(time_info_group.begin(), time_info_group.end(), compare);
	
	int end = 0;
	for (int index = 0; index < time_info_group.size(); index++)
	{
		if (end <= time_info_group[index].start)
		{
			result += 1;
			end = time_info_group[index].end;
		}
	}
}

int  main()
{
	input_data();

	solved();

	cout << result << endl;
}