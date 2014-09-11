// Container With Most Water.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int max_area = 0;
		
		for (int i = 0; i < height.size()-1; i++)
		{
			for (int j = i + 1; j < height.size(); j++)
			{
				int min = height[i] < height[j] ? height[i] : height[j];
				int area = min * (j - i);
				if (area>max_area) max_area = area;
			}
		}

		return max_area;
	}
};

int main()
{
	int A[] = { 1, 2, 3, 4, 5 };

	vector<int> vec(A, A + sizeof(A) / sizeof(int));

	Solution s;
	cout << s.maxArea(vec) << endl;

	return 0;
}

