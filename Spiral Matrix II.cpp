#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
      std::vector<std::vector<int> > result;
      if(n==0) return result;

      for(int i=0; i<n; i++)
      {
        result.push_back(std::vector<int>(n, 0));
      }

      int dir = 1;
      int x, y;
      x = y = 0;
      result[0][0] = 1;
      for(int i=2; i<=n*n; i++)
      {
        switch(dir)
        {
          case 1:
                  if(y+1==n || result[x][y+1]!=0)
                  {
                    dir = 2;
                    i--;
                  }
                  else
                  {
                    y++;
                    result[x][y] = i;
                  }
                  break;

          case 2:
                  if(x+1==n || result[x+1][y]!=0)
                  {
                    dir = 3;
                    i--;
                  }
                  else
                  {
                    x++;
                    result[x][y] = i;
                  }
                  break;
          case 3:
                  if(y==0 || result[x][y-1]!=0)
                  {
                    dir = 4;
                    i--;
                  }
                  else
                  {
                    y--;
                    result[x][y] = i;
                  }
                  break;
          case 4:
                  if(result[x-1][y]!=0)
                  {
                    dir = 1;
                    i--;
                  }
                  else
                  {
                    x--;
                    result[x][y] = i;
                  }
                  break;
        }
      }

      return result;
    }
};

int main()
{
  Solution s;
  std::vector<std::vector<int> > result = s.generateMatrix(3);

  for(int i=0 ; i< result.size(); i++)
  {
    for(int j=0; j<result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}