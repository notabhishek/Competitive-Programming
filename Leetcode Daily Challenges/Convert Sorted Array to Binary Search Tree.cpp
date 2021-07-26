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
    TreeNode* bin(vector<int> &a, int l , int r) {
        if(l > r) 
            return nullptr;
        int mid = ( l + r)/2;
        TreeNode *root = new TreeNode(a[mid]);
        root->left = bin(a, l, mid-1);
        root->right = bin(a, mid + 1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bin(nums, 0 , nums.size()-1);
    }
};
