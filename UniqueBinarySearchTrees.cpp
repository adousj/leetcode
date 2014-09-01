// Unique_Binary_Search_Trees.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int numTrees(int n) {
		int c = 1;
		for (int i = 2; i <= n; i++)
			c = 2 * (2 * i - 1)*c / (i + 1);
		return c;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

