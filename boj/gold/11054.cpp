/**
 * @date 20.06.03
 * @brief BOJ 11054
 * @url https://www.acmicpc.net/problem/11054
 */

#include <iostream>
#include <algorithm>

using namespace std;
namespace boj
{
namespace gold
{
    /**
     * @brief 올라가는 형식의 dp계산하는 메소드
     * @param 
     * @param dp 연산을 저장할 dp 배열
     * @param 배열의 크기
     */
    void get_dp_up(int* dp, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if()
            }
        }
    }

    void get_dp_down(int* dp, int size)
    {

    }

    void solution()
    {
        // 입력
        int time;
        cin >> time;

        int* A = new int[time];
        for (int index = 0; index < time; index++) cin >> A[index];

        //dp 초기화
        int* dp_up = new int[time];
        int* dp_down = new int[time];

        // dp 계산
        get_dp_up(dp_up);
        get_dp_down(dp_down);

        int ans = -100000000;

        // 결과 출력
        cout << ans << endl;
    }
} // !namespace gold
} // !namespace boj