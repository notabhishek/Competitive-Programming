/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector< vector<int>> lvls;
        if(!root)
            return lvls;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> lvl;
        while(q.size()!=1) {
            Node *cur = q.front();
            q.pop();
            if(cur == nullptr) {
                lvls.push_back(lvl);
                lvl.clear();
                q.push(nullptr);
            }
            else {
                lvl.push_back(cur->val);
                for(Node *u : cur->children) 
                    q.push(u);
            }
        }
        lvls.push_back(lvl);
        return lvls;
    }
};
