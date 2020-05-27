#pragma once
#include <iostream>

using namespace std;

namespace boj
{
namespace
{
    void solution()
    {
        int n;
        cin >> n;

        unsigned long long* dp = new unsigned long long[n + 1];
        dp[1] = 1;
        dp[2] = 1;

        for (int index = 3; index <= n; index++)
            dp[index] = dp[index - 1] + dp[index - 2];

        cout << dp[n];
        delete[] dp;
    }
}
}

//int main()
//{
//    int n;
//    cin >> n;
//
//    unsigned long long* dp = new unsigned long long[n + 1];
//    dp[1] = 1;
//    dp[2] = 1;
//
//    for (int index = 3; index <= n; index++)
//        dp[index] = dp[index - 1] + dp[index - 2];
//
//    cout << dp[n];
//    delete[] dp;
//
//    return 0;
//}