// Length of Last Word.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s)
	{
		int n = strlen(s);
		int i;
		for (n-- ; n >= 0; n--)
		{
			if (s[n] != ' ')
				break;
		}
		for ( i = n; i >= 0  ; i--)
		{
			if (s[i] == ' ')
				break;
		}

		return n - i;
	}
};

int main()
{
	char str[] = "a ";

	Solution s;
	cout << s.lengthOfLastWord(str) << endl;

	return 0;
}

