#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> > result;
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i]>0) break;
			if (i > 0 && num[i] == num[i - 1]) continue;
			int sum = -num[i];
			int j = i + 1, k = num.size() - 1;
			while( j < k)
			{
				if (j>i + 1 && num[j - 1] == num[j])
				{
					j++;
					continue;
				}
				if (num[j] + num[i] > 0) break;
				if (num[j] + num[k] < sum)
					j++;
				else if (num[j] + num[k]>sum)
					k--;
				else
				{
					vector<int> vec(3);
					vec[0] = num[i];
					vec[1] = num[j];
					vec[2] = num[k];
					result.push_back(vec);
					j++;
					k--;
				}
			}
		}

		return result;
	}
};

int main()
{
	int A[] = { -1, 0, 1,2, -1, -4 };

	vector<int> vec(A, A + sizeof(A)/sizeof(int));

	Solution s;
	vector<vector<int> > result = s.threeSum(vec);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}

	return 0;
}

