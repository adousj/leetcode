// Triangle.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if (n == 0) return 0;

		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}

		return triangle[0][0];
	}
};

int main()
{
	int a1[] = { 2 };
	int a2[] = { 3, 4 };
	int a3[] = { 6, 5, 7 };
	int a4[] = { 4, 1, 8, 3 };

	vector<vector<int> > vec;
	vec.push_back(vector<int>(a1, a1 + sizeof(a1) / sizeof(int)));
	vec.push_back(vector<int>(a2, a2 + sizeof(a2) / sizeof(int)));
	vec.push_back(vector<int>(a3, a3 + sizeof(a3) / sizeof(int)));
	vec.push_back(vector<int>(a4, a4 + sizeof(a4) / sizeof(int)));

	Solution s;
	cout << s.minimumTotal(vec) << endl;

	return 0;
}

