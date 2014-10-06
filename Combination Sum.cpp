#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = &candidates;
		this->target = target;
		trav(0);
	}

	bool trav(int sum)
	{
		if (sum == target) return true;
		else if (sum > target) return false;
		for (int i = 0; i < candidates->size(); i++)
		{
			trav(sum + (*candidates)[i]);
		}
	}
private:
	vector<int> *candidates;
	int target;
};

int main()
{
	return 0;
}

