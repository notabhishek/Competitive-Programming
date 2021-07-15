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
    int ans;
    int calc(TreeNode* root) {
        if(!root)
            return 0;
        int L = calc(root->left);
        int R =  calc(root->right);
        ans = max(ans , root->val + L + R);
        ans = max(ans , root->val + L);
        ans = max(ans , root->val + R);
        return max(max(max(L , R) , 0) + root->val, 0);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN ;
        calc(root);
        return ans;
    }
};
