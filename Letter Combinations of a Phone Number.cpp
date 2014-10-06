// Letter Combinations of a Phone Number.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		this->digits = &digits;
		result = new vector<string>;
		str = new string(digits.size(), ' ');

		trav(0);

		return *result;
	}

	void trav(int n)
	{
		if (n == digits->size())
		{
			result->push_back(*str);
		}
		else
		{
			int len = 3;
			if ((*digits)[n] == '9' || (*digits)[n] == '7')
				len = 4;
			int t = 0;
			if ((*digits)[n]>'7')
				t = 1;
			for (int i = 0; i < len; i++)
			{
				(*str)[n] = ((*digits)[n] - '2') * 3 + 'a' + i + t;
				trav(n + 1);
			}
		}
	}
private:
	vector<string> *result;
	string *digits;
	string *str;
};

int main()
{
	Solution s;

	vector<string> result = s.letterCombinations("7");
	for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

