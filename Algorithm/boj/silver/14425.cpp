/**
 * @date 20.09.19
 * @brief BOJ 14425
 * @url https://www.acmicpc.net/problem/14425
 * 시간초과
 */

#include <iostream>

using namespace std;

/*********************************************************/
/*                        자료구조                        */
/*********************************************************/

#define TRIE_SIZE 26 // 알파벳 갯수

class Trie
{
private:
	bool is_end;
	Trie* children[TRIE_SIZE];

public:
	Trie()
	{
		init();
	}

	Trie(string str)
	{
		init();
		create_children(str);
	}

	void create_children(string str)
	{
		if (str.empty())
			return;

		if (str.size() == 1)
			is_end = true;

		if (is_exist(str.front()))
		{

			children[char_to_int(str.front())]->create_children(str.substr(1));
		}

		else
			children[char_to_int(str.front())] = new Trie(str.substr(1));
	}

	bool find(string str)
	{
		if (is_exist(str.front()))
		{
			if (str.size() == 1)
			{
				if(is_end)
					return true;
				else
					return false;
			}

			return children[char_to_int(str.front())]->find(str.substr(1));
		}

		return false;
	}

	int char_to_int(char word)
	{
		return word - 'a';
	}

	bool is_exist(char word)
	{
		return this->children[char_to_int(word)];
	}

	void init()
	{
		this->is_end = false;

		for (int index = 0; index < TRIE_SIZE; index++)
			this->children[index] = nullptr;
	}
};

/*********************************************************/
/*                        알고리즘                        */
/*********************************************************/

static int N, M;
static string* N_STR_GROUP;
static string* M_STR_GROUP;
static Trie trie;

void input_data()
{
	cin >> N >> M;

	N_STR_GROUP = new string[N];
	for (int index = 0; index < N; index++)
		cin >> N_STR_GROUP[index];

	M_STR_GROUP = new string[M];
	for (int index = 0; index < M; index++)
		cin >> M_STR_GROUP[index];
}

void init()
{
	for (int index = 0; index < N; index++)
		trie.create_children(N_STR_GROUP[index]);
}

int get_result()
{
	int count = 0;

	for (int index = 0; index < M; index++)
		if (trie.find(M_STR_GROUP[index]))
			count+=1;

	return count;
}

int main()
{
	input_data();
	
	init();
	
	cout << get_result() << endl;
}