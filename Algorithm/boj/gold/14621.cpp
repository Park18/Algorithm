/**
 * @date 20.09.26
 * @url https://www.acmicpc.net/problem/14621
 */

#include <iostream>
#include <vector>

using namespace std;

#define MALE true
#define FEMALE false

struct NODE
{
	bool sex;

	NODE(char sex)
	{
		switch (sex)
		{
		case 'M':
			this->sex = MALE;	
			break;

		case 'W':
			this->sex = FEMALE;
			break;
		}
	}
};

int N, M;
vector<NODE>graph;

int main()
{
	cin >> N >> M;
	for (int loop = 0; loop < N; loop++)
	{
		char sex;
		cin >> sex;
		graph.push_back(NODE(sex));
	}


}
