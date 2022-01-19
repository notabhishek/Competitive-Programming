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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool cycle = false;
        while(slow && fast && fast->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                cycle = true;
                break;
            }
        }
        if(cycle) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return nullptr;
    }
};
