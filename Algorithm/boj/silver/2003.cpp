/**
 * @date 20.10.09
 * @url https://www.acmicpc.net/problem/2003
 * @result ¼º°ø
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;
int result;

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
    int sum = 0;

    while (true)
    {
        if (sum >= M)
            sum -= sequence[start++];

        else if (end == N)
            break;

        else
            sum += sequence[end++];

        if (sum == M)
            result++;
    }
}

int main()
{
    input_data();

    solved();

    cout << result << endl;
}