// Search in Rotated Sorted Array.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		for (int i = 0; i < n; i++)
		{
			if (A[i] == target)
				return i;
		}
		return -1;
	}
};

int main()
{
	return 0;
}

