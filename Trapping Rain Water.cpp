// Trapping Rain Water.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		if (A == NULL || n <= 0) return 0;

		int result = 0;
		int i, j;

		for (i = 0; i < n; i++)
		{
			if (A[i]>0)
				break;
		}
		for (j = n - 1; j >= 0; j--)
		{
			if (A[j] > 0)
				break;
		}

		for (; i < j;)
		{
			int k;

			if (A[i] <= A[j])
			{
				for (k = i+1; k < j && A[k]<=A[i]; k++)
				{
					result += A[i] - A[k];
				}
				i = k;
			}
			else
			{
				for (k = j - 1; k > i && A[k] <= A[j]; k--)
				{
					result += A[j] - A[k];
				}
				j = k;
			}
		}

		return result;
	}
};

int main()
{
	int A[] = { 5, 5, 1, 7, 1, 1, 5, 2, 7, 6 };

	Solution s;
	cout << s.trap(A, sizeof(A) / sizeof(int)) << endl;

	return 0;
}

