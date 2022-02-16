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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        // Head
        ListNode *third = head->next->next;
        ListNode *temp = head;
        head = head->next;
        head->next = temp;
        temp->next = third;
        
        ListNode *prev = temp;
        temp = third;
        while(temp && temp->next) {
            third = temp->next->next;
            ListNode *first = temp;
            temp = temp->next;
            temp->next = first;
            first->next = third;
            prev->next = temp;
            
            // move
            prev = prev->next->next;
            temp = third;
        }
        return head;
    }
};
