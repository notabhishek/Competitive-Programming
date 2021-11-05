/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * @type of head: ListNode
 * @return type: ListNode
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
   		// write your awesome code here
        if(!head || !head->next) return head;
        ListNode* temp = swapPairs(head->next->next);
    	ListNode* nxt = head->next;
        nxt->next = head;
        head->next = temp;
        return head = nxt;
    }
};
