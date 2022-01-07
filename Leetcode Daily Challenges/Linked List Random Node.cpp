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
    ListNode* root;
    Solution(ListNode* head) {
        root = head;
    }
    int getRandom() {
        int idx = 1;
        int ans = 0;
        ListNode* p=root;
        while(p){
            if(rand() % idx == 0) 
                ans=p->val;

            idx++;
            p=p->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
