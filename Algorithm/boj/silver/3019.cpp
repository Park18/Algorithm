/**
 * @date 20.09.27
 * @url https://www.acmicpc.net/problem/3019
 */

#include <iostream>
#include <cstring>

using namespace std;

#define C_MAX 100

int C, P;
int tetris_floor[C_MAX];

void input_data()
{
	cin >> C >> P;

	memset(tetris_floor, -100, C_MAX);
	for (int index = 0; index < C; index++)
		cin >> tetris_floor[index];
}

int get_result()
{
	int count = 0;

	for (int pos = 0; pos < C; pos++)
	{
		switch (P)
		{
		case 1:
			// 0
			count++;

			// 0000
			if (tetris_floor[pos] == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2] && tetris_floor[pos + 2] == tetris_floor[pos + 3])
				count++;

			break;

		case 2:
			// 00
			if (tetris_floor[pos] == tetris_floor[pos + 1])
				count++;

			break;

		case 3:
			// 001
			if (tetris_floor[pos] == tetris_floor[pos + 1] && tetris_floor[pos + 1] + 1 == tetris_floor[pos + 2])
				count++;

			// 10
			if (tetris_floor[pos] == tetris_floor[pos + 1] + 1)
				count++;

			break;

		case 4:
			// 100
			if (tetris_floor[pos] - 1 == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2])
				count++;
			
			// 01
			if (tetris_floor[pos] + 1 == tetris_floor[pos + 1])
				count++;

			break;

		case 5:
			// 000
			if (tetris_floor[pos] == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2])
				count++;

			// 01
			if (tetris_floor[pos] + 1 == tetris_floor[pos + 1])
				count++;

			// 101
			if (tetris_floor[pos] == tetris_floor[pos + 1] + 1 && tetris_floor[pos + 1] + 1 == tetris_floor[pos + 2])
				count++;

			// 10
			if (tetris_floor[pos] == tetris_floor[pos + 1] + 1)
 				count++;

			break;

		case 6:
			// 000
			if (tetris_floor[pos] == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2])
				count++;

			// 00
			if (tetris_floor[pos] == tetris_floor[pos + 1])
				count++;

			// 011
			if (tetris_floor[pos] + 1 == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2])
				count++;

			// 20
			if (tetris_floor[pos] == tetris_floor[pos + 1] + 2)
				count++;
			break;

		case 7:
			// 000
			if (tetris_floor[pos] == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2])
				count++;

			// 02
			if (tetris_floor[pos] + 2 == tetris_floor[pos + 1])
				count++;

			// 110
			if (tetris_floor[pos] == tetris_floor[pos + 1] && tetris_floor[pos + 1] == tetris_floor[pos + 2] + 1)
				count++;

			// 00
			if (tetris_floor[pos] == tetris_floor[pos + 1])
				count++;
			break;
		}
	}

	return count;
}

int main()
{
	input_data();

	cout << get_result() << endl;
}