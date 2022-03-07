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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) {
            if(!l1) return l2;
            else return l1;
        }
        ListNode *h1 = l1 , *h2 = l2 , *h ;
        if( (l1->val) <= ( l2->val)) { 
            h = l1;
            l1 = l1->next;
        }
        else {
            h = l2;
            l2 = l2->next;
        }
        ListNode *head = h;
        while(l1!=NULL && l2!=NULL){
             if((l1 ->val) >= (l2->val)){
                 head->next = l2;
                 l2 = l2->next;
             } else {
                head->next = l1;
                 l1 = l1->next;
             }
           head = head->next; 
        }
        while(l2!=NULL) {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        while(l1!=NULL) {
            head->next=l1;
            l1 = l1->next;
            head = head->next;
        }
        return h;
    }
};
