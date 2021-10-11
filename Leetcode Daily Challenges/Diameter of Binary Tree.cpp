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
    int fans;
    int dfs(TreeNode *root) {
       if(root->left == NULL && root->right == NULL) return 0;
       int lh = 0, rh = 0;
       if(root->left) lh = 1 + dfs(root->left);
       if(root->right) rh = 1 + dfs(root->right);    
       fans = max(fans,lh + rh);
       return max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return fans;
    }
};
