#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
      if(matrix.size()==0 || matrix[0].size()==0) return;

      bool h,v;
      h = v = false;
      for(int i=0; i<matrix.size(); i++)
      {
        if(matrix[i][0]==0)
        {
          v = true;
          break;
        }
      }
      for(int j=0; j<matrix[0].size(); j++)
      {
        if(matrix[0][j]==0)
        {
          h = true;
          break;
        }
      }
      for(int i=1; i<matrix.size(); i++)
      {
        for(int j=1; j<matrix[i].size(); j++)
        {
          if(matrix[i][j]==0)
          {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }
      for(int i=1; i<matrix.size(); i++)
      {
        if(matrix[i][0]==0)
        {
          for(int j=1; j<matrix[i].size(); j++)
          {
            matrix[i][j] = 0;
          }
        }
      }
      for(int j=1; j<matrix[0].size(); j++)
      {
        if(matrix[0][j]==0)
        {
          for(int i=1; i<matrix.size(); i++)
          {
            matrix[i][j] = 0;
          }
        }
      }
      if(v)
      {
        for(int i=0; i<matrix.size(); i++)
        {
          matrix[i][0] = 0;
        }
      }
      if(h)
      {
        for(int i=0; i<matrix[0].size(); i++)
        {
          matrix[0][i] = 0;
        }
      }
    }
};

int main()
{
  int A[][4] = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};

  std::vector<std::vector<int> > v;

  for(int i=0; i<sizeof(A)/sizeof(A[0]); i++)
  {
    v.push_back(std::vector<int>(A[i], A[i]+sizeof(A[i])/sizeof(int)));
  }

  Solution s;
  s.setZeroes(v);


  for(int i=0; i<v.size(); i++)
  {
    for(int j=0; j<v[i].size(); j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;


  return 0;
}