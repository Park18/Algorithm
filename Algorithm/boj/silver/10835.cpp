#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> left;
vector<int> right;

void input_data()
{
	cin >> N;

	int data;
	for (int index = 0; index < N; index++)
	{
		cin >> data;
		::left.push_back(data);
	}

	for (int index = 0; index < N; index++)
	{
		cin >> data;
		::right.push_back(data);
	}
}

void sort()
{
	std::sort(::left.begin(), ::left.end());
	std::sort(::right.begin(), ::right.end());
}

void solution()
{
	
}

int main()
{
	input_data();

	for (auto i : ::left)
		cout << i << endl;
	for (auto i : ::right)
		cout << i << endl;
}