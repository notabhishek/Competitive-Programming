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
const int NAX = 9;
class Solution {
public:
    vector<TreeNode*> dfs(int lo, int hi) {
        vector<TreeNode*> res;
        if(lo > hi) {
            res.push_back(nullptr);
            return res;
        }
        for(int i = lo; i <= hi; ++i) {
            for(auto &L : dfs(lo, i-1)) {
                for(auto &R: dfs(i+1, hi)) {
                    TreeNode *root = new TreeNode(i, L, R);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};
