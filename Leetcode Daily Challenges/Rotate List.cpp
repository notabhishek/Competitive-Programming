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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)              //if list is empty
            return head;
        
        ListNode* temp=head,*prev;
        int x=0;
        
        while(temp)                 //to find size of linked list
        {
            x++;
            prev=temp;
            temp=temp->next;
        }
        
        prev->next=head;            //to make cycle of list (last->next=head)
        
        if(k>x)                     //if value of k is more then x thrn it creates problem
            k=k%x;
        
        x=x-k;                      //how much shift of head required
        
        temp=head;
        while(x--)                  //to find what is actual head after rotation
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        head=temp;
        return head;
    }
};
