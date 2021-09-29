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
    int Length(ListNode *head) {
        if(!head) return 0;
        return 1 + Length(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = Length(head);
        int n = N/k;
        int r = N%k;
        vector<ListNode*> ans;
        for(int part = 1; part <= k; ++part) {
            int sz = n + (part <= r);
            if(sz == 0) 
                ans.push_back(NULL);
            else {
                ListNode *cur = head;
                for(int i = 1; i < sz; ++i) cur = cur->next;
                ListNode *tmp = cur->next;
                cur->next = NULL;
                ans.push_back(head);
                head = tmp;
            }
        }
        return ans;
    }
};
