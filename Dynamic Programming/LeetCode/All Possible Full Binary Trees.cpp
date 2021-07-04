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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector< vector< TreeNode* >> dp(n+1);
        dp[0].push_back(nullptr);
        dp[1].push_back(new TreeNode());
        for(int i = 2; i <= n; ++i) {
            for(int l = 1; l < i-1; ++l) {
                int r = i -1 - l;
                for(auto &u : dp[l]) {
                    for(auto &v : dp[r]) {
                        TreeNode* head = new TreeNode();
                        head->left = u;
                        head->right = v;
                        dp[i].push_back(head);
                    }
                }
            }
        }
        return dp[n];
    }
};
