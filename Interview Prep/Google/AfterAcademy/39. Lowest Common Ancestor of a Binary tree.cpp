/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * @type of root: struct TreeNode
 * @type of node1: integer
 * @type of node2: integer
 * @return type: integer
 */
 
class Solution {
public:
    TreeNode *lcaNode;
    pair<bool, bool> LCA(TreeNode *root, int node1, int node2) {
    	if(!root) return {false, false};
        bool node1found = false;
        bool node2found = false;
       	auto Left = LCA(root->left, node1, node2);
        if(Left.first && Left.second) return Left;
        auto Right = LCA(root->right, node1, node2);
        if(Right.first && Right.second) return Right;
    	
        node1found = root->val == node1 || Left.first || Right.first;
        node2found = root->val == node2 || Left.second || Right.second;
        if(node1found && node2found) lcaNode = root;
        return {node1found,node2found};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, int node1, int node2) {
        // write your awesome code here
    	LCA(root,node1,node2);
        return lcaNode;
    }
};
