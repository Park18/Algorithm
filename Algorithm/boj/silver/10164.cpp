#include <iostream>
#include <vector>

using namespace std;

#define MAX_ROW 15
#define MAX_COL 15
#define MIN_ROW 1
#define MIN_COL 1

struct POS
{
public:
    int row, col;
};

int N, M, K;
POS table[MAX_ROW * MAX_COL + 1];
int dp[MAX_ROW][MAX_COL];

void input_data()
{
    cin >> N >> M >> K;
}

void init_table()
{
    int number = 1;
    for (int row = MIN_ROW; row <= N; row++)
        for (int col = MIN_COL; col <= M; col++)
            table[number++] = { row,col };
}

void init_dp()
{
    for (int row = MIN_ROW; row <= N; row++)
        for (int col = MIN_COL; col <= M; col++)
            dp[row][col] = 1;
}

void calc_dp()
{
    for (int row = MIN_ROW + 1; row <= N; row++)
        for (int col = MIN_COL + 1; col <= M; col++)
            dp[row][col] = dp[row - 1][col] + dp[row][col - 1];       
}

int get_result()
{
    if (K == 0)
        return dp[N][M];

    int d_row = N - table[K].row + 1;
    int d_col = M - table[K].col + 1;

    return dp[table[K].row][table[K].col] * dp[d_row][d_col];
}

int main()
{
    input_data();

    init_table();
    init_dp();

    calc_dp();

    cout << get_result() << endl;
}