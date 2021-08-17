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
    int good(TreeNode *root, int curmax) {
        if(!root) return 0;
        int ans = root->val >= curmax;
        curmax = max(curmax, root->val);
        return ans + good(root->left, curmax) + good(root->right, curmax);
    }
    int goodNodes(TreeNode* root) {
        return good(root, INT_MIN);
    }
};
