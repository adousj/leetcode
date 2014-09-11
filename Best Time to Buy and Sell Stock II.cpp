// Best_Time_to_Buy_and_Sell_Stock_II.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices)
	{
		int result = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				result += prices[i] - prices[i - 1];
		}
		return result;
	}
};

int main()
{
	vector<int> vec;
	
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	
	Solution s;
	cout << s.maxProfit(vec) << endl;

	return 0;
}

