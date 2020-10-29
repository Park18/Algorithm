/**
 * @date 20.10.26
 * @url https://www.acmicpc.net/problem/2143
 * @result 
 */

#include <iostream>
#include <algorithm>

#define MAX 1000

using namespace std;

int T;
int A_size;
int A[MAX];
int B_size;
int B[MAX];
int count = 0;

void input_data()
{
	cin >> T;

	cin >> A_size;
	for (int index = 0; index < A_size; index++)
		cin >> A[index];

	cin >> B_size;
	for (int index = 0; index < B_size; index++)
		cin >> B[index];
}

void solved()
{
	int A_start = 0;
	int A_end = 0;
	int A_sum = 0;

	// A[3] + A[4]까지 실행되고 종료됨
	while (true)
	{
		if (A_sum >= T)
			A_sum -= A[A_start++];

		else if (A_start == A_size)
			break;

		else
			A_sum += A[A_end++];

		if (A_sum != T)
		{
			int B_start = 0;
			int B_end = 0;
			int B_sum = 0;
			
			while (true)
			{
				if (B_sum >= T - A_sum)
					B_sum -= B[B_start++];
			
				else if (B_end == B_size)
					break;
			
				else
					B_sum += B[B_end++];
			
				if (B_sum == T - A_sum)
				{
					cout << "A's = " << A_sum << " B's = " << B_sum << endl;
					::count++;
				}
			}
		}
	}
}

int main()
{
	input_data();

	solved();

	cout << ::count << endl;
}