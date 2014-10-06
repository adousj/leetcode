// Jump Game.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (A == NULL || n <= 0) return false;

		int left, right;
		left = 0;
		right = A[0];
		while (left <= right)
		{
			right = right > left + A[left] ? right : left + A[left];
			if (right >= n - 1) return true;
			left++;
		}

		return false;
	}
};

int main()
{
	int A[] = {0 };

	Solution s;
	cout << s.canJump(A, sizeof(A) / sizeof(int)) << endl;

	return 0;
}

