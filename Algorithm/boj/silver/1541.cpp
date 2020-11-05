/**
 * @date 20.11.02
 * @url https://www.acmicpc.net/problem/1541
 * @result ½ÇÆÐ
 * @test 0+1-2+3+4+5+6-2-1
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define NUM(ch) (ch - '0')
#define P '+'
#define M '-'

vector<int> num_group;
vector<char> operator_group;
int sum = 0;
int minus = 0;
bool is_minus = false;

void input_data()
{
	string expression;
	cin >> expression;

	char num[6];
	int num_index = 0;

	for (int index = 0; index <= expression.size(); index++)
	{
		char text = expression[index];

		if ('0' <= text && text <= '9')
			num[num_index++] = text;

		else
		{
			num[num_index] = NULL;
			num_group.push_back(stoi(num));
			num_index = 0;

			if (text != '\0')
				operator_group.push_back(text);
		}
	}
}

void solved()
{
	sum = num_group[0];

	for (int index = 0; index < operator_group.size(); index++)
	{
		if (operator_group[index] == P)
		{
			if (is_minus)
				::minus += num_group[index + 1];

			else
				sum += num_group[index + 1];
		}

		else
		{
			if (is_minus)
			{
				is_minus = false;

				sum += -::minus;
				::minus = 0;

				sum += -num_group[index + 1];
			}

			else
			{
				is_minus = true;
				::minus += num_group[index + 1];
			}
		}
	}

	//sum += -::minus;
}

int main()
{
	input_data();

	solved();

	cout << sum << endl;
}