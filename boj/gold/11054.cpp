#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int time;
	cin >> time;

	vector<int> A;
	for (int index = 0; index < time; index++)
	{
		int val;
		cin >> val;
		A.push_back(val);

	}

	// 1, 2, 3, 4, 5
	vector<int> dp_1;
	for (int A_index = find(A.begin(), A.end(), *min_element(A.begin(), A.end())) - A.begin(), dp_index = 0; A_index < A.size(); A_index++)
	{
		if (dp_index == 0) 
		{
			dp_1.push_back(A.at(A_index)); 
			continue;
		}

		if (A.at(A_index) > dp_1.at(dp_index - 1))
		{
			dp_1.push_back(A.at(A_index));
			dp_index++;
		}
	}

	for (int index = 0; index < dp_1.size(); index++)
		cout << dp_1.at(index) << ", ";

	// 5, 4, 3, 2, 1
	int* dp_2 = new int[time];
	int dp_2_size = 0;

	// 1, 2, 4, 3, 1
	int* dp_3 = new int[time];

}