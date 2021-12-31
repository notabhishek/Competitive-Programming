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
    pair<int,int> dfs(TreeNode *root, int &ans) {
        if(!root->left && !root->right) return {root->val, root->val};
        int mn = INT_MAX, mx = INT_MIN;
        if(root->left) {
            auto L = dfs(root->left, ans);
            mn = min(mn, L.first);
            mx = max(mx, L.second);
        }
        if(root->right) {
            auto R = dfs(root->right, ans);
            mn = min(mn, R.first);
            mx = max(mx, R.second);
        }
        ans = max(ans, abs(root->val - mn));
        ans = max(ans, abs(root->val - mx));
        return {min(mn, root->val), max(root->val, mx)};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
