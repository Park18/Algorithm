/**
 * @date 20.10.11
 * @url https://www.acmicpc.net/problem/2230
 * @result ¼º°ø
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 10000
#define M_MAX 2000000000

int N, M;
vector<int> sequence;
int result = M_MAX;

void input_data()
{
    cin >> N >> M;

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
    int sub = 0;

    while (true)
    {
        if (sub >= M)
            sub = sequence[end] - sequence[start++];

        else if (end == N)
            break;

        else // (sub < M)
            sub = sequence[end++] - sequence[start];

        if (sub > M)
            result = min(result, sub);

        else if (sub == M)
        {
            result = M;
            return;
        }
    }
}

int main()
{
    input_data();
    sort(sequence.begin(), sequence.end());

    solved();

    cout << result << endl;
}