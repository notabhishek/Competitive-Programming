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
    int dfs(TreeNode *root, int &ans) {
        if(!root) return 0;
        int L = dfs(root->left, ans), R = dfs(root->right, ans);
        ans += abs(L-R);
        return L+R+root->val;
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
