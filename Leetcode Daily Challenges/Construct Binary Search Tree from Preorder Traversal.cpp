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
    TreeNode* dfs(int i, int j, vector<int> &pre) {
        if(i > j) return NULL;
        TreeNode *node = new TreeNode(pre[i]);
        int k = i;
        while(k <= j && pre[k] <= pre[i]) ++k;
        node->left = dfs(i+1, k-1, pre);
        node->right = dfs(k, j, pre);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(0, preorder.size()-1, preorder);
    }
};
