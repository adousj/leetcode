#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1) return s;
		string result;

		for (int i = 0; i < nRows; i++)
		{
			for (int j = i; j < s.size(); j += (nRows - 1) * 2)
			{
				result += s[j];
				if (i != 0 && i != nRows - 1 && j + (nRows - 1 - i) * 2 < s.size())
				{
					result += s[j + (nRows - 1 - i) * 2];
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3) << endl;

	return 0;
}