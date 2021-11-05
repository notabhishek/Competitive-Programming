/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * @type of root: TreeNode
 * @type of req_sum: boolean
 * @return type: integer(1 if path sum exists else 0)
 */
class Solution {
public:
    int pathSumExists(TreeNode* root, int req_sum) {
        // write your awesome code here
        if(!root) return req_sum == 0;
        req_sum -= root->val;
        if(pathSumExists(root->left, req_sum) || 
           pathSumExists(root->right, req_sum)) 
            return true;
        return false;
    }
    
};
