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
/*
O N^2 solution
class Solution {
public:
    int count(TreeNode *root, int targetSum) {
        int ans = 0;
        if(!root) return ans;
        if(targetSum == root->val) ++ans;
        ans += count(root->left, targetSum - root->val);
        ans += count(root->right, targetSum - root->val);
        return ans; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return count(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
*/

//O N using hashmap
class Solution {
public:
    unordered_map<int,int> count;
    int dfs(TreeNode *root,int curSum, int target) {
        if(!root)
            return 0;
        curSum += root->val;
        int ans = count[curSum - target];
        if(curSum == target)++ans;
        
        count[curSum]++;
        ans += dfs(root->left, curSum, target);
        ans += dfs(root->right, curSum, target);
        count[curSum]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};
