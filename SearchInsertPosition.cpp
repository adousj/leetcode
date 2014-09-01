// SearchInsertPosition.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>

using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		for (int i = 0; i < n; i++)
		{
			if (target <= A[i])
				return i;
		}
		return n;
	}
};

int main()
{
	int A[] = {1, 3, 5, 6};

	Solution s;
	cout << s.searchInsert(A,4, 0) << endl;

	return 0;
}

