/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *dfs(TreeNode *u, TreeNode *v, TreeNode *k) {
        if(!u) return nullptr;
        if(u->val == k->val)
            return v;
        TreeNode *L = dfs(u->left, v->left, k);
        if(L) return L;
        return dfs(u->right, v->right, k);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};
