/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * } ListNode;
 */

/**
 * @type of head: ListNode
 * @type of n: integer
 * @return type: ListNode
 */
class Solution {
public:
    ListNode* removeNthNodeFromEnd(ListNode* head, int n) {
   		// write your awesome code here
        ListNode *ptr1= head, *ptr2 = head, *prev = NULL;
      	while(n--) ptr2 = ptr2->next;
        
        while(ptr2) {
            prev = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(prev == NULL) {
        	// delete head 
            prev = head->next;
            delete head;
            return prev;
        }
        prev->next = ptr1->next;
        delete ptr1;
        return head;
    }
};
