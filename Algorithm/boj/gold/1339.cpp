/**
 * @date 20.11.03
 * @url https://www.acmicpc.net/problem/1339
 * @result ¼º°ø
 * @source https://mygumi.tistory.com/156
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h> // pow

using namespace std;

struct ALPHA_INFO
{
	char alphabat;
	int size;

	ALPHA_INFO(char alphabat, int size) : alphabat(alphabat), size(size) {};
};

int N;
int alphabat_size[26];
vector<string> word_group;
vector<ALPHA_INFO> alpha_info_group;
int sum = 0;

bool compare(ALPHA_INFO a, ALPHA_INFO b)
{
	return a.size > b.size;
}

void input_data()
{
	cin >> N;
	for (int index = 0; index < N; index++)
	{
		string word;
		cin >> word;
		word_group.push_back(word);
	}
}

void solved()
{
	for (int row = 0; row < N; row++)
	{
		for (int index = 0; index < word_group[row].size(); index++)
			alphabat_size[word_group[row][index] - 'A'] += pow(10, word_group[row].size() - (index + 1));
	}

	for (int alphabat = 0; alphabat < 26; alphabat++)
	{
		if (alphabat_size[alphabat] != 0)
			alpha_info_group.push_back(ALPHA_INFO(alphabat + 'A', alphabat_size[alphabat]));
	}

	sort(alpha_info_group.begin(), alpha_info_group.end(), compare);

	int num_size = 9;
	for (auto alpha_info : alpha_info_group)
		sum += alpha_info.size * num_size--;
}

int main()
{
	input_data();

	solved();

	cout << sum << endl;
}