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
    TreeNode* build(vector<int> &in, vector<int> &post, int s, int e, int &pidx, unordered_map<int, int> &index) {
        if(s > e) return NULL;
        TreeNode *root = new TreeNode(post[--pidx]);
        int div = index[post[pidx]];
        root->right = build(in, post, div+1, e, pidx, index);
        root->left = build(in, post, s, div-1, pidx, index);
        return root;
    }  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        int pidx = inorder.size(); // postorder index of current element 
        for(int i = 0; i < pidx; ++i) 
            index[inorder[i]] = i;
        return build(inorder, postorder, 0, pidx-1, pidx, index);
    }
};
