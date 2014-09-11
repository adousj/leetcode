// Pascal's Triangle.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result(numRows);

		for (int i = 0; i < numRows; i++)
		{
			result[i] = vector<int>(i+1);
			result[i][0] = 1;
			result[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > vec = s.generate(5);

	return 0;
}

