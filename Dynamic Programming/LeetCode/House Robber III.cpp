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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int ans1 = root->val;
        int ans2 = rob(root->left) + rob(root->right);
        if(root->left && root->left->left) ans1+= root->left->left->val;
        if(root->left && root->left->right) ans1+= root->left->right->val;
        if(root->right && root->right->left) ans1+= root->right->left->val;
        if(root->right && root->right->right) ans1+= root->right->right->val;
        root->val = max(ans1 , ans2);
        return root->val;
    }
};
