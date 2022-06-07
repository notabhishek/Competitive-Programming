/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) 
            return nullptr;
        ListNode *endA = headA;
        ListNode *temp = headA;
        while(endA->next) {
            endA = endA->next;
        }
        endA -> next = headA;
        
        //Detect Cycle in B
        ListNode *slow = headB , *fast = headB;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                //Cycle Detected 
                slow = headB;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                //slow and fast meet at intersection
                endA->next = nullptr; //remove the cycle created earlier
                return slow;
            }
        }
        endA->next = nullptr;
        //no intersection
        return nullptr;
        
    }
};
