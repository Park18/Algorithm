/*****************************************************************
 * https://www.acmicpc.net/problem/1463
 * ����
 * ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
 *  1. X�� 3���� ������ �������� 3���� ������.
 *  2. X�� 2�� ������ �������� 2�� ������.
 *  3. 1�� ����.
 * ���� N�� ������ ��, ���� ���� ���� �� ���� ������ ����ؼ� 1��
 * ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
 *****************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

namespace boj
{
namespace silver
{
    int solution()
    {
        // n �Է�
        int n;
        cin >> n;

        // dp �ʱ�ȭ
        int dp[1000001];
        dp[2] = 1;
        dp[3] = 1;

        // dp ���
        // dp[num]�� �� �� �ִ� ������
        // num�� 2�� ����� ��, dp[num - 1], dp[num / 2]�� ����� ���� �ְ�
        // num�� 3�� ����� ��, dp[num - 1], dp[num / 3]�� ����� ���� �ְ�
        // num�� 2�� 3�� ����� �ƴ� ��, dp[num] = dp[num - 1]�� ����� ���� �ִ�.
        for (int num = 4; num <= n; num++)
        {
            dp[num] = dp[num - 1] + 1;

            if (num % 2 == 0)
                dp[num] = min(dp[num], dp[num / 2] + 1);

            if (num % 3 == 0)
                dp[num] = min(dp[num], dp[num / 3] + 1);
        }

        // ��� ���
        cout << dp[n] << endl;
    }

///---------------------------------------------------------------------------
/// ������ �˰���
///---------------------------------------------------------------------------
#define MAX_SIZE 3    // ���� ���� ���� �� ���̴� �迭�� �ִ� ũ�� 
#define TYPE_1 0      // /2�� ���� ���� �ε���
#define TYPE_2 1      // /3�� ���� ���� �ε���
#define TYPE_3 2      // -1�� ���� ���� �ε���

    typedef struct NEXT_NUM
    {
        int num;        // ���� ���� ��
        int priority;   // �켱����
    }NEXT_NUM;

    int get_next(int x)
    {
        // �� ����
        NEXT_NUM tmp[MAX_SIZE] = { 0 };
        if (x % 2 == 0)
            tmp[TYPE_1].num = x / 2;

        if (x % 3 == 0)
            tmp[TYPE_2].num = x / 3;

        tmp[TYPE_3].num = x - 1;

        // ���� �켱���� ����
        for (int index = 0; index < 3; index++)
        {
            if (tmp[index].num == 0)
            {
                tmp[index].priority = 3;
                continue;
            }

            if (tmp[index].num == 1)
            {
                tmp[index].priority = 0;
                continue;
            }

            if (tmp[index].num % 2 == 0 || tmp[index].num % 3 == 0)
                tmp[index].priority = 1;

            else
                tmp[index].priority = 2;
        }

        // ���� �켱���� ��
        NEXT_NUM* next_num = NULL;
        if (tmp[TYPE_1].priority <= tmp[TYPE_2].priority)
            next_num = &tmp[TYPE_1];
        else
            next_num = &tmp[TYPE_2];

        if(next_num->priority > tmp[TYPE_3].priority)
            next_num = &tmp[TYPE_3];

        return next_num->num;
    }
    
    int get_count(int x)
    {
        if (x == 1)
            return 0;

        return 1 + get_count(get_next(x));
    }

    int solution_2(int argc, char* argv[])
    {
        int x;
        cin >> x;
        cout << get_count(x) << endl;

        return 0;
    }
} // !namespace silver
} // !namespace boj