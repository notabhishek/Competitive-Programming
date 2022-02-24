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
    ListNode *merge(ListNode *a, ListNode *b) {
        if(a == NULL) return b;
        if(b == NULL) return a;
        if(a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }
    ListNode *mergeSort(ListNode *head) {
        if(!head || !head->next) 
            return head;
        ListNode *slow = head, *fast = head, *prev = slow;
        while(!fast && !fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = mergeSort(prev -> next);
        prev -> next = NULL;
        head = mergeSort(head);
        return merge(head, right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
