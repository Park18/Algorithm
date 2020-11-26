/**
 * @date 20.11.25
 * @url https://www.acmicpc.net/problem/10775
 * @result ¼º°ø
 * @souce	https://minerba93.tistory.com/15
 *			https://soobarkbar.tistory.com/181
 */

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int G, P;
vector<int> parent;
int result = 0;

int get_parent(int node)
{
	if (parent[node] == node)
		return node;

	return parent[node] = get_parent(parent[node]);
}

void init()
{
	parent.assign(G + 1, 0);
	for (int index = 0; index <= G; index++)
		parent[index] = index;
}

int main()
{
	cin >> G >> P;

	init();
	for (int loop = 0; loop < P; loop++)
	{
		int g;
		cin >> g;

		if (get_parent(g) == 0)
			break;

		if (get_parent(g))
		{
			result++;
			parent[get_parent(g)] = get_parent(get_parent(g) - 1);
		}
	}

	cout << result << endl;
}