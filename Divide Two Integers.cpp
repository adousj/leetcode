#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;

		long long d1 = abs((long long)dividend);
		long long d2 = abs((long long)divisor);
		int result = 0;
		while (d1 >= d2 )
		{
			long long a = d2;
			int k = 1;
			while ( (a<<1) <= d1 )
			{
				k <<= 1 ;
				a <<= 1;
			}
			result += k;
			d1 -= a;
		}

		if ((dividend<0 && divisor<0) || (dividend>0 && divisor>0))
			return result;
		else
			return -result;
	}
};

int main()
{
	Solution s;
	cout << s.divide(2147483647, 1) << endl;
	return 0;
}