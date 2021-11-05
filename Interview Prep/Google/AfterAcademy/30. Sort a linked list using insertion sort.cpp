/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * } ListNode;
 */

/**
 * @type of head: ListNode
 * @return type: ListNode
 */
class Solution {
public:
    ListNode* insertionSort(ListNode* head) {
   		// write your awesome code here
        if(!head) return head;
        ListNode *cur = head->next;
        while(cur != NULL) {
            ListNode *next = cur->next;
            ListNode *i = head, *previ = NULL;
            while(i != cur && i->val < cur->val) {
                previ = i;
             	i = i->next;
            }
            if(i == cur) {
             	cur = next;
                continue;
            }
            
            // find node just before cur
         	ListNode *prev = head;
            while(prev->next != cur) prev = prev->next;
            
            prev->next = cur->next;
            if(previ == NULL) {
                cur->next  = head;
                head = cur;
            } else {
                previ->next = cur;
                cur->next = i;
            }
            cur = next;
        }
       	return head;
    }
};
