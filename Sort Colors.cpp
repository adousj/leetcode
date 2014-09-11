// SortColors.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	void sortColors(int A[], int n) {
		int red, white, blue;
		red = white = blue = 0;
		for (int i = 0; i < n; i++)
		{
			switch (A[i])
			{
			case 0: red++; break;
			case 1: white++; break;
			case 2: blue++; break;
			}
		}

		int k = 0;
		for (int i = 0; i < red; i++)
			A[k++] = 0;
		for (int i = 0; i < white; i++)
			A[k++] = 1;
		for (int i = 0; i < blue; i++)
			A[k++] = 2;
	}
};

int main()
{
	int A[] = { 0, 1, 2, 2, 1, 1, 0, 2 };

	Solution s;
	s.sortColors(A, sizeof(A) / sizeof(int));

	for (int i = 0; i < sizeof(A) / sizeof(int); i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

