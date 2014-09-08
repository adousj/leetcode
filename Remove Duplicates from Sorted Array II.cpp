#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
      if(A==NULL || n==0) return 0;

      int min = A[0] - 1;
      for(int i=0; i<n; i++)
      {
        for(int j=i+2; j<n; j++)
        {
          if(A[i] == A[j])
            A[j] = min;
          else
            break;
        }
      }

      int k = 0;
      for(int i=0; i<n; i++)
      {
        if(A[i] == min)
           continue;
        else
        {
          A[k++] = A[i];
        }
      }

      return k;
    }
};


int main()
{
  int A[] = {1,1,1,2,2,3};

  Solution s;
  int n = s.removeDuplicates(A, sizeof(A)/sizeof(int));

  for(int i=0; i<n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}