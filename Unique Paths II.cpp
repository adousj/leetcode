#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		auto vec = obstacleGrid;
		for (auto &v : vec)
		{
			for (auto &i : v)
			{
				i = 0;
			}
		}
		int x = obstacleGrid.size();
		//assert(x > 0);
		int y = obstacleGrid[0].size();
		for (int i = 0; i < x; i++)
		{
			if (obstacleGrid[i][0] == 1) break;
			vec[i][0] = 1;
		}
		for (int i = 0; i < y; i++)
		{
			if (obstacleGrid[0][i] == 1) break;
			vec[0][i] = 1;
		}

		for (int i = 1; i < x; i++)
		{
			for (int j = 1; j < y; j++)
			{
				if (obstacleGrid[i][j] == 1) continue;
				vec[i][j] += vec[i - 1][j] + vec[i][j - 1];
			}
		}

		return vec[x - 1][y - 1];
	}
};

int main()
{
	vector<vector<int> > grid = { {1,0} };

	Solution s;
	cout << s.uniquePathsWithObstacles(grid) << endl;

	return 0;
}