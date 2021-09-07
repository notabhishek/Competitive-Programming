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
    ListNode* recRec(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *left = recRec(head->next);
        head->next->next = head;
        head->next = NULL;
        return left;
    }
    ListNode* reverseList(ListNode* head) {
        // recursive
        return recRec(head);
        // iterative
        if(!head || !head->next) return head;
        ListNode *cur = head, *next, *prev = NULL;
        while(cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return head = prev;
    }
};
