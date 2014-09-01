// SingleNumberII.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <map>

using namespace std;




class Solution {
public:
	int singleNumber(int A[], int n) {
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			/*if (m.find(i) != m.end())
			{
				m[i] = 1;
			}
			else*/
				m[A[i]] += 1;
		}
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			if (it->second != 3)
			{
				cout << it->first<<endl;
				return it->first;
			}
		}
		return 0;
	}
};

int main()
{
	int A[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 5 };
	Solution s;
	s.singleNumber(A, sizeof(A)/sizeof(int));

	return 0;
}

