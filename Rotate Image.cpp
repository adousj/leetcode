// Rotate Image.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0) return;
		int xx , yy;
		xx = yy = matrix.size();
		int x = (xx+1) / 2;
		int y = yy / 2;

		for (int i = 0; i < x; i++)
		{
			for (int  j = 0; j < y; j++)
			{
				int tmp[4];
				tmp[0] = matrix[j][i];
				tmp[1] = matrix[i][xx - 1 - j];
				tmp[2] = matrix[xx - 1 - j][xx - i - 1];
				tmp[3] = matrix[xx - 1 - i][j];

				matrix[j][i] = tmp[3];
				matrix[i][xx - 1 - j] = tmp[0];
				matrix[xx - 1 - j][xx - i - 1] = tmp[1];
				matrix[xx - 1 - i][j] = tmp[2];
			}
		}
	}
};

int main()
{
	int a1[] = { 1, 2, 3 };
	int a2[] = { 4, 5, 6 };
	int a3[] = { 7, 8, 9 };

	vector<vector<int> > vec;
	vec.push_back(vector<int>(a1, a1 + sizeof(a1) / sizeof(int)));
	vec.push_back(vector<int>(a2, a2 + sizeof(a2) / sizeof(int)));
	vec.push_back(vector<int>(a3, a3 + sizeof(a3) / sizeof(int)));

	Solution s;
	s.rotate(vec);

	return 0;
}

