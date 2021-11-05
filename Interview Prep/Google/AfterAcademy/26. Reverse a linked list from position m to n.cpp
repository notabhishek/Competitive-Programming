/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * } ListNode;
 */

/**
 * @type of head: ListNode
 * @type of m: integer
 * @type of n: integer
 * @return type: ListNode
 */
class Solution {
public:
    void print(ListNode *head) {
    	if(!head) {
        	cout << endl; return;
        }
        cout << head->val << " " ;
        print(head->next);
    }
    ListNode* reversePartialList(ListNode* head, int m, int n) {
   		// write your awesome code here
        ListNode *headPrev = NULL, *tailNext = NULL;
        ListNode *cur = head;
        for(int pos = 1; pos < m; ++pos) {
            headPrev = cur;
        	cur = cur->next;
        }
        
        // Reverse here
        ListNode *prev = NULL, *next;
        for(int pos = m; pos <= n; ++pos) {
        	next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // join the parts here 
        if(headPrev) {
            if(headPrev->next)
            	headPrev->next->next = cur; 
            
        	headPrev->next = prev;
        } else {
            head->next = cur;
            head = prev;
        }
        return head;
    }
};
