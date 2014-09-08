#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
      if(root==NULL) return false;

      this->sum = sum;
      nums = new std::vector<int>;

      return trav(root, 1);
    }

    bool trav(TreeNode *node, int n)
    {
      if(node->left==NULL && node->right==NULL)
      {
        int tmp = 0;
        for(int i=0; i<n-1; i++)
          tmp += (*nums)[i];
        tmp += node->val;
        return tmp == sum;
      }
      else
      {
        while(n > nums->size()) nums->push_back(0);
        (*nums)[n-1] = node->val;
        return (node->left!=NULL && trav(node->left, n+1) ) \
          || (node->right!=NULL && trav(node->right, n+1) );
      }
    }

private:
  std::vector<int> *nums;
  int sum;
};

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);

  // root = new TreeNode(1);
  // root->left = new TreeNode(2);

  Solution s;
  cout << s.hasPathSum(root, 22) << endl;

  return 0;
}