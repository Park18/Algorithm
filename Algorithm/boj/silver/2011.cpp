#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 5000
#define CHAR_ZERO '0'

string num;
int dp[MAX_SIZE];

void input_data() { cin >> num; }

void init_dp() { dp[0] = 1; }

void calc_dp() 
{
	for (int i = 0; i < num.size(); i++)
	{
		dp[i + 1] = dp[i];

		if()
	}
}

int main()
{
	input_data();
	
	init_dp();


}