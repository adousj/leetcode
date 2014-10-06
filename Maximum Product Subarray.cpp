#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		if (n == 0) return 0;
		
		int max_pre, min_pre, maxx;
		max_pre = min_pre = maxx = A[0];
		for (int i = 1; i < n; i++)
		{
			int tmp_max_pre = max(max(max_pre * A[i], min_pre * A[i]), A[i]);
			int tmp_min_pre = min(min(max_pre * A[i], min_pre * A[i]), A[i]);
			maxx = max(tmp_max_pre, maxx);
			max_pre = tmp_max_pre;
			min_pre = tmp_min_pre;
		}

		return maxx;
	}
};

int main()
{
	int A[] = { -4, -3, -2 };

	Solution s;

	cout << s.maxProduct(A, sizeof(A) / sizeof(int)) << endl;

	return 0;
}

