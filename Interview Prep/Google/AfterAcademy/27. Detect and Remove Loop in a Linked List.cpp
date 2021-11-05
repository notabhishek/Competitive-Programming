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
    ListNode* detectAndRemoveLoop(ListNode* head) {
   		// write your awesome code here
        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next) {
        	slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next) return head; // no loop
        
        // loop exists 
        // check self loop edge case 
        if(slow->next == slow) {
         	slow ->next = NULL;
            return head;
        }
        // move 1 pointer (length of loop) ahead of head
        ListNode *cur  = slow;
        ListNode *ptr2 = head, *prev = NULL;
        while(cur->next != fast) {
            cur = cur-> next;
            prev = ptr2;
            ptr2 = ptr2-> next;
        }
        prev = ptr2;
        ptr2 = ptr2->next;
        
        ListNode *ptr1 = head;
        while(ptr1 != ptr2) {
        	ptr1 = ptr1->next;
            prev = ptr2;
            ptr2 = ptr2->next;
        }
        prev->next = NULL;
       	return head;
    }
};
