#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode *root) {
      // result = new std::vector<int>;
      // trav(root);
      // return *result;

      result = new std::vector<int>;
      if(root==NULL) return *result;
      iter(root);
      return *result;
    }

    void iter(TreeNode *root)
    {
      stack<pair<TreeNode *, bool> > nodes;
      nodes.push(make_pair(root, false));

      while(!nodes.empty())
      {
        pair<TreeNode*, bool> *node = &nodes.top();
        if(node->second)
        {
          result->push_back(node->first->val);
          nodes.pop();
        }
        else
        {
          node->second = true;
          if(node->first->right!=NULL)
            nodes.push(make_pair(node->first->right, false));
          if(node->first->left!=NULL)
            nodes.push(make_pair(node->first->left, false));
        }
      }
    }

    void trav(TreeNode *node)
    {
      if(node==NULL) return;

      trav(node->left);
      trav(node->right);

      result->push_back(node->val);
    }

private:
  std::vector<int> *result;
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution s;
  std::vector<int> v = s.postorderTraversal(root);
  for(int i=0; i<v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  return 0;
}