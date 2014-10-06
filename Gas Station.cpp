#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.size() == 0 || gas.size() != cost.size()) return -1;

		if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
			return -1;
		
		int g = 0;
		int start = 0;
		int n = gas.size();
		for (int i = 0; i < n * 2; i++)
		{
			int c = i % n;
			int next = (i + 1) % n;

			if (g + gas[c] - cost[c] >= 0)
			{
				g += gas[c] - cost[c];
				if (next == start)
					return next;
			}
			else
			{
				g = 0;
				start = next;
			}
		}
	}
};

int main()
{
	int A1[] = { 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66 };
	int A2[] = { 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };

	vector<int> gas(A1, A1 + sizeof(A1) / sizeof(int));
	vector<int> cost(A2, A2 + sizeof(A2) / sizeof(int));

	Solution s;
	cout << s.canCompleteCircuit(gas, cost) << endl;

	return 0;
}

