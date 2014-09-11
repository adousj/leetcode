// Search a 2D Matrix.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;

		int a, b, c;
		a = 0;
		c = m - 1;
		b = (a + c) / 2;
		
		while (a < c-1)
		{
			if (target < matrix[b][0])
			{
				c = b;
				b = (a + c)/2;
			}
			else if (target > matrix[b][0])
			{
				a = b;
				b = (a + c) / 2;
			}
			else
				return true;
		}

		if (a == c-1)
		{
			if (target < matrix[c][0])
			{
				return binary_search(matrix[a].begin(), matrix[a].end(), target);
			}
			else
				return binary_search(matrix[c].begin(), matrix[c].end(), target);
		}
		else
		{
			return binary_search(matrix[a].begin(), matrix[a].end(), target);
		}

		return false;
	}
};

int main()
{
	int a1[] = { 1, 3 };
	int a2[] = { 10, 11, 16, 20 };
	int a3[] = { 23, 30, 34, 50 };

	vector<vector<int> > vec;
	vec.push_back(vector<int>(a1, a1 + sizeof(a1) / sizeof(int)));
	//vec.push_back(vector<int>(a2, a2 + sizeof(a2) / sizeof(int)));
	//vec.push_back(vector<int>(a3, a3 + sizeof(a3) / sizeof(int)));

	//int A[][2] = { { -10, -8 }, { -6, -5 }, { -2, -2 }, { -1, 0 }, { 3, 4 }, { 7, 7 }, { 8, 9 }, { 10, 10 }, { 11, 11 }, { 12, 14 }, { 15, 16 }, { 17, 19 }, { 20, 21 }, { 22, 22 }, { 25, 27 }, { 28, 30 }, { 32, 32 }, { 35, 36 } };
	/*int A[][4] = {
		{ 1, 3, 5, 7 },
		{ 10, 11, 16, 20 },
		{ 23, 30, 34, 50 } };
*/
	/*for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		vec.push_back(vector<int>(A[i], A[i] + sizeof(A[i]) / sizeof(int)));
	}*/
		
	Solution s;
	cout << s.searchMatrix(vec, 3) << endl;

	return 0;
}

