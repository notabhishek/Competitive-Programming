/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * @type of head1: ListNode
 * @type of head2: ListNode
 * @return type: ListNode
 */
class Solution {
public:
    ListNode* addRec(ListNode *head1, ListNode *head2, int carry) {
   		if(!head1 && !head2 && !carry) return NULL;
        if(head1) carry += head1->val;
        if(head2) carry += head2->val;
    	ListNode *sum = new ListNode(carry % 10);
        sum->next = addRec(head1?head1->next:head1, head2?head2->next:head2,
                                carry/10);
        return sum;
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
   		// write your awesome code here
        return addRec(head1, head2, 0);
    }
};
