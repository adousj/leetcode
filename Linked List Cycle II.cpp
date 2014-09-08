#include <iostream>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      std::map<ListNode*, bool> mm;

      ListNode *node = head;
      while(node!=NULL)
      {
        if(mm.find(node)!=mm.end())
          return node;

        mm[node] = true;
        node = node->next;
      }

      return node;
    }
};

int main()
{
  ListNode *head = new ListNode(1);

  head->next = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  head->next->next = n3;
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = n3;

  Solution s;
  cout << (s.detectCycle(head) == n3) << endl;

  return 0;
}