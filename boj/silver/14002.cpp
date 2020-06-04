#include <iostream>
#include <algorithm>

using namespace std;
//int main()
//{
//	int size;
//	cin >> size;
//
//	int* A = new int[size];
//	for (int index = 0; index < size; index++) cin >> A[index];
//
//	int* dp = new int[size];
//	dp[0] = A[0];
//
//	int pos = 1;
//	for (int index = 1; index < size; index++)
//	{
//		if (A[index - 1] < A[index])
//			dp[pos++] = A[index];
//	}
//
//	cout << pos << endl;
//	sort(dp, dp + pos);
//	for (int index = 0; index < pos; index++) cout << dp[index] << " ";
//}