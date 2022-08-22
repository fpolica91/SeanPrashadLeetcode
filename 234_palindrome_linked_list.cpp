#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *check_palindrome_util(ListNode *current, ListNode *head, bool &flag) {
  if (current == NULL)
    return head;
  ListNode *corresponding_node =
      check_palindrome_util(current->next, head, flag);

  if (current->val != corresponding_node->val) {
    flag = false;
  }
  return corresponding_node->next;
}

bool isPalindrome(ListNode *head) {
  bool flag = true;
  check_palindrome_util(head, head, flag);
  return flag;
}