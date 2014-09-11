// reverse_integer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sym = 1;
		if (x < 0)
		{
			sym = -1;
			x = -x;
		}
		int result = 0;
		while (x)
		{
			int a = x % 10;
			result = result * 10 + a;
			x /= 10;
		}
		return result * sym;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(-1230) << endl;

	return 0;
}

