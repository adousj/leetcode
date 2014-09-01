// single_number.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;


class Solution {
public:
	int singleNumber(int A[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i] == -1) continue;
			bool found = true;
			for (int j = i+1; j < n; j++)
			{
				if (A[i] == A[j])
				{
					found = false;
					A[j] = -1;
					break;
				}
			}
			if (found)
			{
				return A[i];
			}
		}

		return A[n - 1];
	}
};

int main()
{
	int A[] = { 2,2,1 };
	Solution s;
	cout << s.singleNumber(A, 3) << endl;

	return 0;
}
