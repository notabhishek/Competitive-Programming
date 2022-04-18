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
 void inorder(TreeNode* root, int &k, int &ans){
 	if(root == NULL) return;
    if(ans != -1) return;
 	inorder(root->left, k, ans);
     k--;
 	if(k == 0) {
        ans = root->val;
        return;
    }
 	inorder(root->right, k, ans);
 }

 int kthSmallest(TreeNode* root, int k) {
 	if(root==NULL) return 0;
    int ans = -1;
 	inorder(root, k, ans);
 	return ans;
 }
};
