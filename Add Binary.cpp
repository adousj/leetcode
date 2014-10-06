#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string c;
		int q = 0;
		int i = a.size()-1;
		int j = b.size() - 1;
		while (q == 1 || i>=0 || j>=0)
		{
			if (i >= 0)
				q += a[i] - '0';
			if (j>=0)
				q += b[j] - '0';

			c.insert(c.begin(), q % 2+'0');
			q /= 2;
			i--;
			j--;
		}
		
		return c;
	}
};

int main()
{
	string a = "11";
	string b = "1";
	
	Solution s;
	cout << s.addBinary(a, b) << endl;

	return 0;
}

