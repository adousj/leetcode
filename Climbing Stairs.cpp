// ClimbingStairs.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
	Solution(){
		tmp[0] = 1;
		tmp[1] = 1;
	}

	int climbStairs(int n) {
		if ( tmp.find(n)!=tmp.end() )
			return tmp[n];
		else
		{
			int n1, n2;
			n1 = climbStairs(n - 1);
			n2 = climbStairs(n - 2);
			tmp[n] = n1+n2;
			return n1+n2;
		}
	}
private:
	map<int, int> tmp;
};

int main()
{
	Solution s;
	cout << s.climbStairs(3) << endl;

	return 0;
}

