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
    void dfs(TreeNode *root, int cur, int &ans) {
        if(!root) return;
        cur = cur * 10 + root->val;
        if(!root->left && !root->right) {
            ans += cur;
            return;
        }
        if(root->left) dfs(root->left, cur, ans);
        if(root->right) dfs(root->right, cur, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};
