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
    TreeNode* clone(TreeNode *root , int inc) {
        if(!root)
            return nullptr;
        TreeNode *R = new TreeNode(root->val + inc);
        R->left = clone(root->left , inc);
        R->right = clone(root->right , inc);
        return R;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*> ();
        vector<vector<TreeNode*>> trees(n+1);
        trees[0].push_back( nullptr );
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j<=i; ++j) {
                // catalan [j] += catalan[j-1] * catalan[i-j]
                for(int k = 0 ; k < trees[j-1].size(); ++k) 
                    for(int l = 0; l < trees[i-j].size(); ++l) {
                        TreeNode *temp = new TreeNode (j);
                        temp->left = trees[j-1][k];
                        temp->right = clone(trees[i-j][l] , j);
                        trees[i].push_back(temp);
                    }
            }
        }
        return trees[n];
    }
};
