class Solution {
public:
    ListNode* merge2Lists(ListNode* A , ListNode* B) {
        if(!A && !B)
            return nullptr;
        if(!A)
            return B;
        if(!B)
            return A;
        if(A->val > B->val) {
            B->next = merge2Lists(A , B->next);
            return B;
        }
        else {
            A->next = merge2Lists(A->next , B);
            return A;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        ListNode *R = lists[0];
        for(int i = 1; i < lists.size(); ++i) {
            R = merge2Lists(R , lists[i]);
        }
        return R;
    }
};
