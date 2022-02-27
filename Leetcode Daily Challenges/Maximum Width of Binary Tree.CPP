using ull = unsigned long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, ull> firstIndex;
        return dfs(root, 0, 0, firstIndex);
    }
    ull dfs(TreeNode* root, int level, ull index, unordered_map<int, ull>& firstIndex) {
        if(!root) return 0;
        if(firstIndex.find(level) == firstIndex.end()) {
            firstIndex[level] = index;
        }
        ull left = dfs(root->left, level + 1, 2 * index, firstIndex);
        ull right = dfs(root->right, level + 1, 2 * index + 1, firstIndex);
        return max(index - firstIndex[level] + 1, max(left, right));
    }
};
