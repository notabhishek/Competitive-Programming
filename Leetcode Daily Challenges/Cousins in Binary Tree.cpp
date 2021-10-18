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
    bool isCousins(TreeNode* root, int x, int y) {
        // level order traversal
        queue<TreeNode*> q; 
        q.push(root);
        int sz;
        while(!q.empty()) {
            sz = q.size();
            // unordered_set<int> lvl;
            bool xInLvl = false;
            bool yInLvl = false;
            while(sz--){
                TreeNode *cur = q.front(); 
                q.pop();
                
                // lvl.insert(cur->val);
                if(cur->val == x) xInLvl = true;
                if(cur->val == y) yInLvl = true;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                // check if they are children to same parent
                if(cur->left && cur->left->val == x && cur->right && cur->right->val == y) 
                    return false;
                if(cur->left && cur->left->val == y && cur->right && cur->right->val == x) 
                    return false;
            }
            if(xInLvl && yInLvl) return true;
            // if(lvl.count(x) && lvl.count(y)) return true;
        }
        return false;
    }
};
