// Unique Paths.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int max = m > n ? m : n;
		int min = m < n ? m : n;
		__int64 xl, mnl;
		xl = mnl = 1;
		for (int i = max; i <= m + n - 2; i++)
		{
			mnl *= i;
		}
		for (int i = 2; i <= min - 1; i++)
		{
			xl *= i;
		}
		return mnl / xl;
	}
};

int main()
{
	Solution s;

	cout << s.uniquePaths(3, 3) << endl;

	return 0;
}

