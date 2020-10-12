/**
 * @date 20.10.10
 * @url https://www.acmicpc.net/problem/1806
 * @result ½ÇÆÐ
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10000
#define S_MAX 987654321

int N, S;
vector<int> sequence;
int result = N_MAX;

void input_data()
{
    cin >> N >> S;

    for (int loop = 0; loop < N; loop++)
    {
        int num;
        cin >> num;
        sequence.push_back(num);
    }
}

void solved()
{
    int start = 0;
    int end = 0;
    int sum = 0;

    while (true)
    {
        if (sum > S)
            sum -= sequence[start++];

        else if (sum == S)
            sum += sequence[end++];

        else if (end == N)
            break;

        else if (sum < S)
            sum += sequence[end++];

        if(sum >= S)
            result = min(result, end - start);
    }
}

int main()
{
    input_data();

    solved();

    if (result == N_MAX)
        result = 0;

    cout << result << endl;
}