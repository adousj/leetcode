#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = 0;

		stack<int> sta;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				sta.push(i);
			else
			{
				if (!sta.empty())
				{
					s[sta.top()] = s[i] = ' ';
					sta.pop();
				}
			}
		}

		for (int i = 0; i < s.size(); )
		{
			if (s[i] == ' ')
			{
				int j;
				for (j = i + 1; j < s.size(); j++)
				{
					if (s[j] != ' ') break;
				}
				len = max(len, j - i);
				i = j + 1;
			}
			else
				i++;
		}
		return len;
	}
};

int main()
{
	Solution s;
	cout << s.longestValidParentheses(")()())") << endl;
	cout << s.longestValidParentheses("()(()") << endl;
	cout << s.longestValidParentheses(")") << endl;
	cout << s.longestValidParentheses("()(()") << endl;
	cout << s.longestValidParentheses(")(((((()())()()))()(()))(") << endl;

	return 0;
}

