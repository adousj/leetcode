#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 1) return 1;
		int len = 0;
		int start = 0;
		for (int i = 1; i < s.size(); i++)
		{
			bool isRepeat = false;
			int j;
			for (j = start; j < i; j++)
			{
				if (s[j] == s[i])
				{
					isRepeat = true;
					break;
				}
			}
			if (isRepeat)
			{
				len = max(len, i-start);
				start = j + 1;
			}
			else
			{
				len = max(len, i - start + 1);
			}
		}

		return len;
	}
};

int main()
{
	string str = "c";

	Solution s;
	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}

