#include <iostream>

using namespace std;

#define MAX_SIZE 1001
#define MIN_SIZE 1

int N;
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

#define EAST 0
#define SOUTH 1

#define STRAWBERRY 0
#define CHOCO 1
#define BANANA 2

void input_data()
{
	cin >> N;
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> map[i][j];
}

bool is_right_order(int before_drink, int now_milk)
{
	if ((before_drink == STRAWBERRY && now_milk == CHOCO) ||
		(before_drink == CHOCO && now_milk == BANANA) ||
		(before_drink == BANANA && now_milk == STRAWBERRY))
		return true;

	return false;
}

bool is_right_range(int axis)
{
	if (MIN_SIZE <= axis && axis <= N)
		return true;

	return false;
}

int get_before_dp(int row, int col, int way)
{
	if (way == EAST)
		col -= 1;
	else
		row -= 1;
	
	if (is_right_range(row) && is_right_range(col))
		return dp[row][col];

	return 0;
}

void calc_dp()
{
	int before_drink = -1;

	for (int col = 1; col <= N; col++)
	{
		for (int row = 1; row <= N; row++)
		{
			// 처음 마시는가?
			if (before_drink == -1 && map[row][col] == 0)
			{
				dp[row][col] = 1;
				before_drink = 0;
			}

			// 순서에 맞는가?
			// 맞으면 max(동 + 1, 남 + 1), before_drink 갱신
			// 틀리면 max(동, 남)
			else if (is_right_order(before_drink, map[row][col]))
			{
				dp[row][col] = max(get_before_dp(row, col, EAST) + 1, get_before_dp(row, col, SOUTH) + 1);
				before_drink = map[row][col];
			}

			else
				dp[row][col] = max(get_before_dp(row, col, EAST), get_before_dp(row, col, SOUTH));

		}

	}
}

void test_print_dp()
{
	cout << endl;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << dp[i][j] << " ";

		cout << endl;
	}
}

int main()
{
	input_data();

	calc_dp();

	test_print_dp();

	cout << dp[N][N] << endl;
}
