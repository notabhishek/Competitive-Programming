/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * } ListNode;
 */

/**
 * @type of head1: ListNode
 * @type of head2: ListNode
 * @return type: ListNode
 */
class Solution {
public:
    ListNode* mergeSortedLists(ListNode* head1, ListNode* head2) {
   		// write your awesome code here
        if(!head1) return head2;
        if(!head2) return head1;
        
        if(head1->val > head2->val) {
        	head2->next = mergeSortedLists(head1, head2->next);
            return head2;
        } else {
        	head1->next = mergeSortedLists(head1->next, head2);
            return head1;
        }
    }
};
