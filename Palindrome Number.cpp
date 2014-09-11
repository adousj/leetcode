// Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0) return false;
		int reverse = 0;
		for (int tmp = x; tmp != 0; tmp /= 10)
			reverse = reverse * 10 + tmp % 10;
		return reverse == x;
	}
};

int main()
{
	Solution s;
	cout << s.isPalindrome(121) << endl;
	return 0;
}

