/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            sum = 0;
            while(sz--) {
                TreeNode *u = q.front();
                q.pop();
                sum += u->val;
                if(u->left) 
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            if(q.empty())
                return sum;
        }
        return 0;
    }
};
