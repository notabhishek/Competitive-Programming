// Problem: https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    set<TreeNode*> ans;
    TreeNode* Del(TreeNode *root,TreeNode *par, set<int> &todel) {
        if(!root) return root;
        root->left = Del(root->left, root, todel);
        root->right= Del(root->right,  root, todel);
        if(todel.find(root->val) != todel.end()) {
            if(root->left) ans.insert(root->left);
            if(root->right) ans.insert(root->right);
            if(par != NULL) {
                if(par->right && par->right->val == root->val) {
                    par->right = NULL;
                }
                if(par->left && par->left->val == root->val) {
                    par->left = NULL;
                }
                delete root;
                return NULL;
            }
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> todel(to_delete.begin(), to_delete.end());
        root = Del(root, NULL, todel);
        if(root && !todel.count(root->val)) ans.insert(root);
        vector<TreeNode*> res(ans.begin(), ans.end());
        return res;
    }
};
