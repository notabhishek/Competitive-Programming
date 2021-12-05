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
    pair<int,int> dfs(TreeNode* root) {
        if(!root) return {0, 0};
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        int take = root->val + L.second + R.second;
        int dont = L.first + R.first;
        return {max(take, dont), dont};
    }
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
};
