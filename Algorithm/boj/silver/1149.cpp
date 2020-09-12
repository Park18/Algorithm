/**
 * @date 20.05.23
 * @brief BOJ 1149
 * @url https://www.acmicpc.net/problem/1149
 */

#include <iostream>
#include <algorithm>

#define MAX_SIZE 1000
#define COLOR_SIZE 3
#define R 0
#define G 1
#define B 2

using namespace std;
namespace boj
{
namespace silver
{
    /**
     * @brief DP를 이용한 문제풀이, 스터디 후에 풀음
     */
    void solution()
    {
        int dp[1001][3];
        int arr[1001][3];
        int count;
        cin >> count;
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> arr[i][j];
            }
        }

        dp[0][R] = arr[0][R];
        dp[0][G] = arr[0][G];
        dp[0][B] = arr[0][B];

        for (int i = 1; i < count; i++) {
            dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + arr[i][R];
            dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + arr[i][G];
            dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + arr[i][B];
        }

        int result = min(min(dp[count - 1][R], dp[count - 1][G]), dp[count - 1][B]);

        cout << result << endl;

    }

    enum COLOR
    {
        RED,
        GREEN,
        BLUE
    };

    class DP
    {
    public:
        int cost;
        int color;

        DP() {};
        DP(int cost, int color) :cost(cost), color(color) {};
    };

    int find(int* first, int val)
    {
        int* ptr = std::find(first, first + COLOR_SIZE, val);

        if (ptr == first)
            return COLOR::RED;

        else if (ptr == first + 1)
            return COLOR::GREEN;

        else
            return COLOR::BLUE;
    }

    /**
     * @brief DP를 이용한 문제풀이, 틀린 문제풀이
     * @detail 모든 집을 칠하는 비용의 최솟 값이지만
     *         1, 2,   3
     *         1, 100, 100 이 주어졌을 때의 최소 비용은 3이지만
     *         이 메소드의 알고리즘은 101을 출력한다.
     */
    void test_1()
    {
        // 입력
        int n;
        cin >> n;

        int** color_cost = new int* [n + 1];
        for (int n_index = 1; n_index <= n; n_index++)
        {
            color_cost[n_index] = new int[COLOR_SIZE];
            for (int cost_index = 0; cost_index < COLOR_SIZE; cost_index++)
                cin >> color_cost[n_index][cost_index];
        }

        // dp 초기화
        DP* dp = new DP[n];
        int cost = *min_element(color_cost[1], color_cost[1] + 3);
        dp[1] = DP(cost, boj::silver::find(color_cost[1], cost));

        // dp 계산
        for (int index = 2; index <= n; index++)
        {
            if (dp[index - 1].color == COLOR::RED)
                cost = min(color_cost[index][GREEN], color_cost[index][BLUE]);

            else if (dp[index - 1].color == COLOR::GREEN)
                cost = min(color_cost[index][RED], color_cost[index][BLUE]);

            else
                cost = min(color_cost[index][GREEN], color_cost[index][RED]);

            dp[index] = DP(dp[index - 1].cost + cost, find(color_cost[index], cost));
        }

        // 결과 출력
        cout << dp[n].cost << endl;
    }

    /**
     * @brief DP를 이용한 문제풀이, 시간초과
     */
    void test_2()
    {
        int n;
        cin >> n;

        int color[MAX_SIZE + 1][COLOR_SIZE];
        for (int index = 1; index <= n; index++)
        {
            for (int color_index = 0; color_index < COLOR_SIZE; color_index)
                cin >> color[index][color_index];
        }

        int dp[MAX_SIZE + 1][COLOR_SIZE];
        dp[0][R] = color[0][R];
        dp[0][G] = color[0][G];
        dp[0][B] = color[0][B];

        for (int index = 2; index <= n; index++)
        {
            dp[index][R] = min(dp[index - 1][G], dp[index - 1][B]) + color[index][R];
            dp[index][G] = min(dp[index - 1][R], dp[index - 1][B]) + color[index][G];
            dp[index][B] = min(dp[index - 1][G], dp[index - 1][R]) + color[index][B];
        }


        cout << min(min(dp[n][R], dp[n][G]), dp[n][B]) << endl;
    }

} // !namespace silver
} // !namespace boj