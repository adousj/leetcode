// Plus One.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			int tmp = digits[i] + carry;
			carry = tmp / 10;
			digits[i] = tmp % 10;
			if (carry == 0) return digits;
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	int A[] = { 9, 9 };
	vector<int> vec(A, A + sizeof(A)/sizeof(int));

	Solution s;
	s.plusOne(vec);

	return 0;
}

