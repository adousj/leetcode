#include <iostream>

using namespace std;

class Solution {
public:
	double pow(double x, long n) {
		if (n == 0) return 1;
		double result = 1;
		double xx = x;
		long m = abs(n);
		while (m)
		{
			if (m & 1)
				result *= xx;
			xx *= xx;
			m = abs(m>>1);
		}
		if (n < 0)
			return 1 / result;
		else
			return result;
	}
};

int main()
{
	Solution s;
	cout << s.pow(1, 2147483648) << endl;

	return 0;
}

