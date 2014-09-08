#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
      int x, y, min;
      x = y = min =0;
      int dif = 0;
      for(int i=1; i<prices.size(); i++)
      {
        if(prices[i] < prices[min])
        {
          min = i;
        }
        else if(prices[i]-prices[min] > dif)
        {
          x = min;
          y = i;
          dif = prices[y] - prices[x];
        }
      }
      return dif;
    }
};

int main()
{
  int A[] = {1,2,3,4,5,6,3,2,11};
  std::vector<int> v(A, A+sizeof(A)/sizeof(int));

  Solution s;
  cout << s.maxProfit(v) << endl;

  return 0;
}