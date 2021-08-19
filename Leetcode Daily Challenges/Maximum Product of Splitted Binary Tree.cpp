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
using ll = long long;
class Solution {
public:
    int sum(TreeNode *r) {
        if(!r) return 0;
        return r->val + sum(r->left) + sum(r->right);
    }
    ll tot , ans;
    int dfs(TreeNode *root) {
        if(!root) return 0;
        ll sum = root->val; 
        sum += dfs(root->left);
        sum += dfs(root->right);
        ans = max(ans, sum * (tot - sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        tot = sum(root);
        ans = 0;
        dfs(root);
        int mod = 1e9 + 7;
        return ans % mod;
    }
};
