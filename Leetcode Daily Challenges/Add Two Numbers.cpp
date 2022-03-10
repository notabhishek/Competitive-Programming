/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *add(ListNode *a, ListNode *b, int c) {
        if(!a && !b && c == 0) 
            if(c == 0) return nullptr;
        int d = c;
        if(a) d+= a->val;
        if(b) d+= b->val;
        ListNode *cur = new ListNode();
        cur->val = d%10;
        cur->next = add(a?a->next : a, b? b->next : b, d/10);
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
