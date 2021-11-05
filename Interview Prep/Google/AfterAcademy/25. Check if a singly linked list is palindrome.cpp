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
 * @return type: int
 */
class Solution {
public:
    // calculate the length of a linked list
    int Length(ListNode* head) {
    	int len = 0;
        while(head) {
        	++len; head = head->next;
        }
        return len;
    }
    // reverse a linked list 
   	ListNode* reverse(ListNode* head) {
     	if(!head || !head->next) return head;
        ListNode *cur = head, *prev = NULL, *next;
        while(cur){
        	next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return head = prev;
    }
    void printList(ListNode *head){
        while(head) {
        	cout << head->val << " ";
        	head = head->next;
        }
        cout << endl;
    }
    int isPalindrome(ListNode* head) {
   		// write your awesome code here
        int len = Length(head);
        if(len == 1) return true;
        // go to mid element and reverse the array 
        int move = (len + 1)/2 - 1;
        ListNode *mid = head;
        while(move--) mid = mid -> next;
        mid->next = reverse(mid->next);
        ListNode *ptr1 = head, *ptr2 = mid->next;
        for(int i = 0; i < len/2; ++i) {
        	if(ptr1->val != ptr2->val) return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
};
