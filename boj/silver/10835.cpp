#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> left_dummy;
vector<int> right_dummy;

void input_data()
{
	cin >> N;

	int data;
	for (int index = 0; index < N; index++)
	{
		cin >> data;
		left_dummy.push_back(data);
	}

	for (int index = 0; index < N; index++)
	{
		cin >> data;
		right_dummy.push_back(data);
	}
}

void dummy_sort()
{
	std::sort(left_dummy.begin(), left_dummy.end(), greater<int>());
	std::sort(right_dummy.begin(), right_dummy.end(), greater<int>());
}

int solution()
{
	int result = 0;
	int left_index = 0;
	int right_index = 0;

	while (1)
	{
		if (left_dummy[left_index] > right_dummy[right_index])
		{
			result = max(result, result + right_dummy[right_index]);
			left_index++;
			right_index++;
		}

		else
			right_index++;

		if ((N <= left_index) || (N <= right_index))
			break;
	}

	return result;
}

int main()
{
	input_data();

	dummy_sort();

	cout << solution() << endl;
}