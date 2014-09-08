#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode *root) {
      std::vector<std::vector<int> > v;
      if(root==NULL) return v;

      std::vector<TreeNode *> nodes;
      nodes.push_back(root);
      nodes.push_back(NULL);
      int ii = 0;
      while(ii<nodes.size()-1)
      {
        TreeNode *node = nodes[ii++];
        if(node==NULL)
        {
          nodes.push_back(NULL);
        }
        else
        {
          if(node->left!=NULL)
            nodes.push_back(node->left);
          if(node->right!=NULL)
            nodes.push_back(node->right);
        }
      }

      std::vector<int> *vec = new std::vector<int>;
      for(int i=0; i<nodes.size(); i++)
      {
        TreeNode *node = nodes[i];
        if(node==NULL)
        {
          v.push_back(*vec);
          vec = new std::vector<int>;
        }
        else
        {
          vec->push_back(node->val);
        }
      }

      return v;
    }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution s;
  std::vector<std::vector<int> > v = s.levelOrder(root);

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