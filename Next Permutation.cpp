#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		if (!next_permutation(num.begin(), num.end()))
			sort(num.begin(), num.end());
	}
};

int main()
{
	int A[] = { 1, 2, 3 };
	vector<int> vec(A, A+sizeof(A)/sizeof(int));

	Solution s;
	s.nextPermutation(vec);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

