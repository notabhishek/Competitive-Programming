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
    bool findNode(TreeNode *root, int k) {
        if(!root) return false;
        if(root->val == k) return true;
        if(k > root->val) return findNode(root->right, k);
        return findNode(root->left, k);
    }
    bool dfs(TreeNode *cur, int k, TreeNode *root) {
        if(!cur) return false;
        if(2*cur->val != k && findNode(root, k - cur->val)) return true;
        if(dfs(cur->left, k, root) || dfs(cur->right, k, root)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k , root);
    }
};
