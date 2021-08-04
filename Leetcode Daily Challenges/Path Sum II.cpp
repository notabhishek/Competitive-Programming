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
    vector<int> path;
    vector<vector<int>> res;
    void dfs(TreeNode *root, int req) {
        if(!root) return;
        path.push_back(root->val);
        req -= root->val;
        
        if(!root->left && !root->right){
            if(req == 0) 
                res.push_back(path);
        }
        if(root->left) dfs(root->left, req);
        if(root->right) dfs(root->right, req);
        
        req += root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};
