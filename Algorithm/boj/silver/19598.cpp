/**
 * @date 20.09.27
 * @url https://www.acmicpc.net/problem/19598
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define START false
#define END true

class TIME
{
public:
	int time;
	bool is_end;

	TIME(int time, bool is_end) : time(time), is_end(is_end) {};

	bool operator< (TIME& time)
	{
		if (this->time == time.time)
		{
			if (this->is_end)
				return true;

			else
				return false;
		}

		return this->time < time.time;
	}
};

int N;
vector<TIME> time;
int max_room = 0;

int main()
{
	cin >> N;
	for (int loop = 0; loop < N; loop++)
	{
		int start_time, end_time;
		cin >> start_time >> end_time;
		time.push_back(TIME(start_time, START));
		time.push_back(TIME(end_time, END));
	}

	sort(time.begin(), time.end());

	int room = 0;
	for (auto time_info : time)
	{

		if (time_info.is_end)
			room--;
		else
			room++;

		max_room = max(max_room, room);
	}

	cout << max_room << endl;
}