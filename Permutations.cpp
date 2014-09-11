// Permutations.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > vec;
		sort(num.begin(), num.end());
		vec.push_back(num);
		while ( next_permutation(num.begin(), num.end()) )
		{
			vec.push_back(num);
		}
		return vec;
	}
};

int main()
{
	int A[] = { 0, -1, 1 };
	vector<int> vec(A, A + sizeof(A) / sizeof(int));

	Solution s;
	vector<vector<int> > result = s.permute(vec);

	return 0;
}

