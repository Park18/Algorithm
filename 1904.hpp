#include <iostream>

#define MAX_SIZE 1000001

using namespace std;

namespace my
{
    int test_main()
    {
        int dp[MAX_SIZE] = { 0 };
        dp[1] = 1; dp[2] = 2;

        int n;
        cin >> n;

        for (int index = 3; index <= n; index++)
            dp[index] = (dp[index - 2] + dp[index - 1]) % 15746;

        cout << dp[n] << '\n';
    }
}