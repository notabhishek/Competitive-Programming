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
    int levels(TreeNode *root) {
        if(!root) return 0;
        return 1 + levels(root->left);
    }
    bool find(TreeNode* root, int mid, int N){
        if(!root) return false;
        if(N==1) return true;
        N/=2;
        if(mid <=N) return find(root->left, mid, N);
        return find(root->right, mid-N, N);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int H = levels(root) - 1; 
        int N = (1<<H); //max nodes in last level
        int lo = 1, hi = N;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(find(root, mid, N)) 
                lo = mid+1;
            else
                hi = mid-1;
        }
        int internalNodes = N - 1;
        int leafNodes = lo-1;
        return internalNodes + leafNodes;
    }
};
