class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()!=1) {
            Node *temp = q.front();
            q.pop();
            if(!temp) {
                q.push(NULL);
            }else {
                temp->next = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};
