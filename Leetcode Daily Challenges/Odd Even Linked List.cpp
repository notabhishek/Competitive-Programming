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
class Solution{
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *evenHead = NULL;
        if(head) evenHead = head->next;
        ListNode *o = head, *e = evenHead;
        while(o && e && e->next) {
            o->next = e->next;
            o = o->next;
            e->next = e->next->next;
            e = e->next;
        }
        o->next = evenHead;
        return head;
    }
};
