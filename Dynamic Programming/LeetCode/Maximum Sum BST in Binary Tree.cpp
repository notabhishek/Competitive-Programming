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
    const static int INF = 1e7;
    
    // can also use an array / vector to return these values from dfs
    struct node{
        bool isbst;
        int sum;
        int mx;
        int mn;
        node() : sum(0), isbst(1), mx(-INF), mn(INF) {};
    };
    
    int ans;
    node* dfs(TreeNode *root) {
        node* res = new node();
        res->mx = res->mn = res->sum = root->val;
        
        if(root->left) {
            node* tmp = dfs(root->left);
            res->sum += tmp->sum;
            res->mx = max(res->mx, tmp->mx);
            res->mn = min(res->mn, tmp->mn);
            if(!tmp->isbst || tmp->mx >= root->val) res->isbst = 0;
        }
        
        if(root->right) {
            node* tmp = dfs(root->right);
            res->sum += tmp->sum;
            res->mx = max(res->mx, tmp->mx);
            res->mn = min(res->mn, tmp->mn);
            if(!tmp->isbst || tmp->mn <= root->val) res->isbst = 0;
        }
        if(res->isbst) ans = max(ans, res->sum);
        return res;
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
