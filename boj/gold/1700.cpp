/**
 * @date 20.11.22
 * @url https://www.acmicpc.net/problem/1700
 * @result ����
 */

#include <iostream>
#include <vector>
#include <queue>

#define FREE -1

using namespace std;

struct PRODUCT_INFO
{
	int priority;
	int plug_index;

	PRODUCT_INFO() {};
	PRODUCT_INFO(int priority, int plug_index) :priority(priority), plug_index(plug_index) {};
};

int N, K;
int count = 0;
vector<int> plug;
queue<int> order;
vector<PRODUCT_INFO> product_info;
vector<int> index_info;

void input_data()
{
	cin >> N >> K;
	
	plug.assign(N, FREE);
	product_info.assign(K + 1, PRODUCT_INFO(0, FREE));

	for (int loop = 0; loop < K; loop++)
	{
		int product;
		cin >> product;

		order.push(product);
		product_info[product].priority++;
	}
}

void solved()
{
	int index = 0;

	for (int loop = 0; loop < K; loop++)
	{
		int product = order.front();
		order.pop();

		// 1. ��ǰ ��� x, �÷��� �� �� ����
		if (plug[index] == FREE && product_info[product].plug_index == FREE)
		{
			plug[index] = product; // �ʿ��Ѱ�?
			product_info[product].priority--;
			product_info[product].plug_index = index;

			++index %= N;

		}

		// 2. �̹� ��ǰ �����
		else if(product_info[product].plug_index != FREE)
		{
			product_info[product].priority--;
		}

		// 3. �̻��, �÷��� �� �� ����
		else
		{
			// �켱 ���� ���� ��ǰ ã��
			int change_index = 0;
			for (int plug_index = 0; plug_index < N - 1; plug_index++)
			{
				int product_1 = plug[plug_index];
				int product_2 = plug[plug_index + 1];

				if (product_info[product_1].priority > product_info[product_2].priority)
				{
					change_index = product_info[product_2].plug_index;
					product_info[product_2].plug_index = FREE;
				}

				else
				{
					change_index = product_info[product_1].plug_index;
					product_info[product_1].plug_index = FREE;
				}
			}

			plug[change_index] = product;
			product_info[product].priority--;
			product_info[product].plug_index = change_index;

			::count++;
		}
	}
}

int main()
{
	input_data();

	solved();

	cout << ::count << endl;
}