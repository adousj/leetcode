#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0) return "";
		int ii = 0;
		int len = 0;

		for (int i = 1; i < s.size() - 1; i++)
		{
			int j;
			for (j = 1; i - j >= 0 && i + j < s.size(); j++)
			{
				if (s[i - j] != s[i + j])
				{
					break;
				}
			}
			if (j - 1>len)
			{
				ii = i;
				len = j - 1;
			}
		}

		int iii = 0;
		int lenn = 0;

		for (int i = 1; i < s.size(); i++)
		{
			int j;
			for (j = 1; i - j >= 0 && i + j - 1 < s.size(); j++)
			{
				if (s[i - j] != s[i + j - 1])
				{
					break;
				}
			}
			if (j - 1>lenn)
			{
				iii = i;
				lenn = j - 1;
			}
		}

		if (2*len+1 > 2*lenn)
			return s.substr(ii - len, len * 2 + 1);
		else
			return s.substr(iii - lenn, 2 * lenn);
	}
};

int main()
{
	string str = "tattarrattat";

	Solution s;
	cout << s.longestPalindrome(str) << endl;

	return 0;
}

