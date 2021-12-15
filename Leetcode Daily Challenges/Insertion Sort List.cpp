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
    ListNode* insertionSortList(ListNode* head) {
        for(int i = 2;; ++i) {
            ListNode *prev = NULL, *cur = head;
            for(int j = 1; j < i; ++j) {
                prev = cur;
                cur = cur->next;
            }
            if(cur == NULL)
                break;
            
            if(head->val >= cur->val) {
                prev->next = cur->next;
                cur->next = head;
                head = cur;
            } else {
                ListNode *ptr = head;
                while(ptr->next->val < cur->val) 
                    ptr = ptr->next;
                
                if(ptr != cur) {
                    prev->next = cur->next;
                    cur->next = ptr->next;
                    ptr->next = cur;
                }
            }
        }
        return head;
    }
};
