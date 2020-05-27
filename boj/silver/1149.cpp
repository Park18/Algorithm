/**
 * @date 20.05.23
 * @brief BOJ 1149
 */

#include <iostream>
#include <algorithm>

using namespace std;

namespace boj
{
namespace silver
{
#define MAX_SIZE 1001
#define COLOR_SIZE 3

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

    void test()
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
} // !namespace silver
} // !namespace boj

using namespace boj::silver;
int main()
{
    boj::silver::test();


    return 0;
}