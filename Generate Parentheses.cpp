// Generate Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		this->n = n;
		str = new char[2*n + 1];
		str[2*n] = '\0';
		result = new vector<string>();
		travGen(1, 0, 0);
		delete[] str;
		return *result;
	}

	void travGen(int m, int l_num, int r_num)
	{
		if (m > 2*n) trans();
		else
		{
			if (l_num < n)
			{
				str[m - 1] = '(';
				travGen(m + 1, l_num + 1, r_num);
				
			}
			if (r_num< n && l_num>r_num)
			{
				str[m - 1] = ')';
				travGen(m + 1, l_num, r_num + 1);
			}
		}
	}

	void trans()
	{
		result->push_back(string(str));
	}

private:
	char *str;
	vector<string> *result;
	int n;
};

int main()
{
	Solution s;

	vector<string> result = s.generateParenthesis(3);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}


	return 0;
}

