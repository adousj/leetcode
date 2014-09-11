// RemoveElement.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int new_len = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == elem)
			{
				for (int j = i + 1; j < n; j++)
				{
					A[j - 1] = A[j];
				}
				i--;
				new_len--;
				n--;
			}
			new_len++;
		}

		return new_len;
	}
};

int main()
{
	//int A[] = { 1, 2, 3, 4, 5, 5, 6, 7, 3, 2 };
	int A[] = { 4, 5 };

	Solution s;
	cout << s.removeElement(A, sizeof(A) / sizeof(int), 4) << endl;

	return 0;
}

