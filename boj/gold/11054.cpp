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
     * @brief �ö󰡴� ������ dp����ϴ� �޼ҵ�
     * @param 
     * @param dp ������ ������ dp �迭
     * @param �迭�� ũ��
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
        // �Է�
        int time;
        cin >> time;

        int* A = new int[time];
        for (int index = 0; index < time; index++) cin >> A[index];

        //dp �ʱ�ȭ
        int* dp_up = new int[time];
        int* dp_down = new int[time];

        // dp ���
        get_dp_up(dp_up);
        get_dp_down(dp_down);

        int ans = -100000000;

        // ��� ���
        cout << ans << endl;
    }
} // !namespace gold
} // !namespace boj