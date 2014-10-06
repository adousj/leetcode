// N-Queens.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		this->n = n;
		boards = new vector<vector<string> >;
		board = new int[n];
		xx = new int[n];
		yy = new int[n];
		xy = new int[2 * n - 1];
		yx = new int[2 * n - 1];
		memset(xx, 0, n*sizeof(int));
		memset(yy, 0, n*sizeof(int));
		memset(xy, 0, (2 * n - 1)*sizeof(int));
		memset(yx, 0, (2 * n - 1)*sizeof(int));

		trav(0);
		return *boards;
	}

	void trav(int m)
	{
		if (m >= n)
		{
			vector<string> result;
			for (int i = 0; i < n; i++)
			{
				string str;
				for (int j = 0; j < n; j++)
				{
					if (j == board[i])
						str.push_back('Q');
					else
						str.push_back('.');
				}
				result.push_back(str);
			}
			boards->push_back(result);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (xx[m] == 0 && yy[i] == 0 && xy[m + i] == 0 && yx[m - i + n - 1] == 0)
				{
					xx[m] = yy[i] = xy[m + i] = yx[m - i + n - 1] = 1;
					board[m] = i;
					trav(m + 1);
					xx[m] = yy[i] = xy[m + i] = yx[m - i + n - 1] = 0;
				}
			}
		}

	}
private:
	int n;
	vector<vector<string> > *boards;
	int *board;
	int *xx, *yy, *xy, *yx;
};
int main()
{
	Solution s;
	vector<vector<string> > result = s.solveNQueens(4);

	return 0;
}

