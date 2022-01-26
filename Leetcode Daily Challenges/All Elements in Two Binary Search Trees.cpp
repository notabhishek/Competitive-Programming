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
    void inorder(TreeNode *root, vector<int> &a) {
        if(!root) return;
        inorder(root->left, a); 
        a.push_back(root->val); 
        inorder(root->right, a);
    }
    vector<int> merge(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size(), i = 0, j = 0;
        vector<int> c;
        while(i < n && j < m) {
            if(a[i] <= b[j]) 
                c.push_back(a[i++]);
            else
                c.push_back(b[j++]);
        }
        while(i<n) c.push_back(a[i++]);
        while(j<m) c.push_back(b[j++]);
        return c;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);
        return merge(a, b);
    }
};
