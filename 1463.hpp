/*****************************************************************
 * https://www.acmicpc.net/problem/1463
 * 문제
 * 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
 *  1. X가 3으로 나누어 떨어지면 3으로 나눈다.
 *  2. X가 2로 나누어 떨어지면 2로 나눈다.
 *  3. 1을 뺀다.
 * 정수 N이 줘졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을
 * 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
 *****************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

namespace my
{

#define MAX_SIZE 3    // 다음 수를 정할 때 쓰이는 배열의 최대 크기 
#define TYPE_1 0      // /2일 때의 값의 인덱스
#define TYPE_2 1      // /3일 때의 값의 인덱스
#define TYPE_3 2      // -1일 때의 값의 인덱스

typedef struct NEXT_NUM
{
    int num;        // 다음 값의 수
    int priority;   // 우선순위
}NEXT_NUM;

int get_next(int x)
{
    // value setting
    NEXT_NUM tmp[MAX_SIZE] = { 0 };
    if (x % 2 == 0)
        tmp[TYPE_1].num = x / 2;

    if (x % 3 == 0)
        tmp[TYPE_2].num = x / 3;

    tmp[TYPE_3].num = x - 1;

    // value's priority setting
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

    // value's priority compare
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

int test_main(int argc, char* argv[])
{
    int x;
    cin >> x;
    cout << get_count(x) << endl;

    return 0;
}

}

namespace h
{

#define ARR_SIZE 1000001


int test_main() {
    int input = 0;
    cin >> input;

    int* arr = new int[ARR_SIZE];
    fill_n(arr, ARR_SIZE, 0);
    arr[1] = 0;

    for (int i = 2; i <= input; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
    }

    cout << arr[input] << endl;
    delete[] arr;
    return 0;
}
}