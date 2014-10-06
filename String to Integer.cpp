#include <iostream>

using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int i = 0;
		int len = strlen(str);
		while(i < len)
		{
			if (('0' <= str[i] && str[i] <= '9') || str[i] == '+' || str[i]=='-') break;
			if (str[i] != ' ') return 0;
			i++;
		}
		int sign  = 1;
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
		{
			sign = 1;
			i++;
		}

		if (str[i]<'0' || str[i]>'9') return 0;
		long long result = 0;
		while (i < len && '0' <= str[i] && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			if (result >= 2147483648)
			{
				break;
			}
			i++;
		}

		if (result >= 2147483647 && sign ==1)
			return 2147483647;
		else if (result > 2147483648 && sign ==-1)
			return 2147483648;

		result *= sign;
		return result;
	}
};

int main()
{
	char *str = "-2147483648";

	Solution s;
	cout << s.atoi(str) << endl;

	return 0;
}

