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
    int rangeSumBST(TreeNode* root, int lo, int hi) {
        if(!root) return 0;
        return (root->val >= lo && root->val<=hi ? root->val : 0) + rangeSumBST(root->left, lo, hi) + rangeSumBST(root->right, lo, hi);
    }
};
