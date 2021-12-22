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
    int length(ListNode *head) {
        int len = 0;
        while(head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head, *prev = NULL, *next;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *cur = head1, *tmp;
        while(head2) {
            tmp = head2->next;
            head2->next = cur->next;
            cur->next = head2;
            
            cur = cur->next->next;
            head2 = tmp;
        }
        return head1;
    }
    void print(ListNode *head) {
        while(head) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        int n = length(head), n1 = (n+1)/2;
        ListNode *head1 = head, *head2 = head1;
        
        // separate the 2 parts 
        for(int i = 1; i < n1; ++i) {
            head2 = head2->next;
        }
        ListNode *tmp = head2;
        head2 = head2->next;
        tmp->next = NULL;
        
        head2 = reverse(head2);
        // print(head1);
        // print(head2);
        head = merge(head1, head2);
    }
};
