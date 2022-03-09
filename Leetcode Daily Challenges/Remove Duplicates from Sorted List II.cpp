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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int , int> m;
        ListNode *cur = head;
        while(cur) {
            m[cur->val]++;
            cur = cur->next;
        }
        cur = head;
        ListNode *prev = nullptr;
        for(auto &i : m) {
            if(i.second==1) {
                cur->val = i.first;
                prev = cur;
                cur = cur->next;
            }
        }
        if(prev) {
            prev->next = nullptr;
            return head;
        }else {
            return nullptr;
        }
    }
};
