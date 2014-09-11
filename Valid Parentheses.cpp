// Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> que;

		for (int i = 0; i < s.size(); i++)
		{
			if (que.empty())
				que.push(s[i]);
			else
			{
				char ch = que.top();
				char sh = s[i];
				switch (sh)
				{
				case '}':
					if (ch!='{')
						return false;
					que.pop();
					break;
				case ']':
					if (ch != '[')
						return false;
					que.pop();
					break;
				case ')':
					if (ch != '(')
						return false;
					que.pop();
					break;
				default:
					que.push(sh);
				}
			}
		}

		return que.empty();
	}
};

int main()
{
	string str = "{()}";

	Solution s;
	cout << s.isValid(str) << endl;

	return 0;
}

