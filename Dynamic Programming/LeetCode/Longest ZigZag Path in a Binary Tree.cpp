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
    map< TreeNode* , pair<int, int>> dp;
    void zig(TreeNode *root) {
        if(dp.count(root)) {
            return;
        }
        int L = 0 , R = 0;
        if(root->left) {
            zig(root->left);
            L = max(L, 1 + dp[root->left].second);
        }
        if(root->right) {
            zig(root->right);
            R = 1  + dp[root->right].first;
        }
        dp[root] = {L, R};
    }
    int longestZigZag(TreeNode* root) {
        zig(root);
        int ans = 0;
        for(auto &i : dp) ans = max(ans, max(i.second.first, i.second.second));
        return ans;
    }
};
