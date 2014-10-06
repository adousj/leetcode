#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		map<int, int> hash;

		for (vector<int>::iterator it = numbers.begin(); it != numbers.end() ; it++)
		{
			int n = target - (*it);
			if (hash.find(n) != hash.end())
			{
				result.push_back(hash[n]);
				result.push_back(it - numbers.begin() + 1);
				return result;
			}
			hash[*it] = it - numbers.begin() + 1;
		}
	}
};

int main()
{
	int A[] = { 3,2,4};
	vector<int> vec(A, A + sizeof(A) / sizeof(int));

	Solution s;
	vector<int> result = s.twoSum(vec, 6);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}

