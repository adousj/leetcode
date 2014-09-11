// Minimum Path Sum.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;


// Time Limit Exceeded
class Solution1 {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.size() == 0) return 0;

		this->grid = &grid;
		this->m = grid.size();
		this->n = grid[0].size();
		this->max_sum = -1;

		trav(grid[0][0], 1, 1);

		return max_sum;
	}

	void trav(int sum, int x, int y)
	{
		if (x == m && y == n)
		{
			if(max_sum == -1 || sum < max_sum) max_sum = sum;
			return;
		}

		if (x < m) trav(sum + (*grid)[x][y-1], x + 1, y);
		if (y < n) trav(sum + (*grid)[x-1][y], x, y+1);
	}
private:
	vector<vector<int> > *grid;
	long max_sum;
	int m;
	int n;
};

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.size() == 0) return 0;
		int x = grid.size();
		int y = grid[0].size();

		for (int i = 1; i < y; i++)
		{
			grid[0][i] += grid[0][i - 1];
		}

		for (int i = 1; i < x; i++)
		{
			grid[i][0] += grid[i-1][0];
		}

		for (int i = 1; i < x; i++)
		{
			for (int j = 1; j < y; j++)
			{
				grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
			}
		}

		return grid[x-1][y-1];
	}
};

int main()
{
	int a1[] = { 1, 1, 1 };
	int a2[] = { 2, 3, 1 };

	vector<vector<int> > vec;
	vec.push_back(vector<int>(a1, a1 + sizeof(a1) / sizeof(int)));
	vec.push_back(vector<int>(a2, a2 + sizeof(a2) / sizeof(int)));

	Solution s;
	int result = s.minPathSum(vec);

	return 0;
}

