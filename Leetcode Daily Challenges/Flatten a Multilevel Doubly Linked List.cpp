/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    pair<Node*, Node*> merge(Node* head) {
        if(!head) return {NULL, NULL};
        if(!head->child && !head->next) return {head, head};
        
        if(head->child) {
            pair<Node*, Node*> clist = merge(head->child);
            if(head->next) {
                pair<Node*, Node*> rlist = merge(head->next);
                head->next = clist.first;
                clist.first->prev = head;
                head->child = NULL;
                clist.second->next = rlist.first;
                rlist.first->prev = clist.second;
                clist.second->child = NULL;
                return {head, rlist.second};
            } else {
                head->next = clist.first;
                clist.first->prev = head;
                head->child = NULL;
                return {head, clist.second};
            }
        } else {
            return {head, merge(head->next).second};
        }
    }
    Node* flatten(Node* head) {
        pair<Node*, Node*> res = merge(head);
        return res.first;
    }
};
