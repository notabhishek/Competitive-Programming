/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        Node *u;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                u = q.front(); q.pop();
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
                u->next = n == 0? NULL : q.front();
            }
        }
        return root;
    }
};
