// NQueensII.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		ii = new int[n];
		jj = new int[n];
		ipj = new int[2 * n - 1];
		imj = new int[2 * n - 1];
		memset(ii, 0, n*sizeof(int));
		memset(jj, 0, n*sizeof(int));
		memset(ipj, 0, (2 * n - 1)*sizeof(int));
		memset(imj, 0, (2 * n - 1)*sizeof(int));
		num = 0;

		travNqueens(n, 0);

		delete[] ii;
		delete[] jj;
		delete[] ipj;
		delete[] imj;
		return num;
	}

	void travNqueens(int n, int j)
	{
		if (n == j)
		{
			num++;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (ii[i] == 0 && jj[j] == 0 && ipj[i + j] == 0 && imj[i - j + n - 1] == 0)
			{
				ii[i] = jj[j] = ipj[i + j] = imj[i - j + n - 1] = 1;

				travNqueens(n, j + 1);

				ii[i] = jj[j] = ipj[i + j] = imj[i - j + n - 1] = 0;
			}
		}
	}

private:
	int *ii;
	int *jj;
	int *ipj;
	int *imj;
	int num;
};

int main()
{
	Solution s;

	cout << s.totalNQueens(1) << endl;

	return 0;
}

