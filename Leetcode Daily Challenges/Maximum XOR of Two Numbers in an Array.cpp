class Trie {
    const static int B = 30;
public: 
    Trie* child[2];
    Trie() {
        child[0] = child[1] = NULL;
    }
    void insert(int n) {
        bitset<B+1> bit(n);
        Trie *root = this;
        for(int i = B; i >= 0; --i) {
            if(!root->child[ bit[i] ])
                root->child[bit[i]] = new Trie();
            root = root->child[bit[i]];
        }
    }
    int maxXor(int x) {
        int ans = 0;
        bitset<B+1> bit(x);
        Trie *root = this;
        for(int i = B; i >= 0; --i) {
            if(root->child[ 1 - bit[i] ]) {
                root = root->child[ 1 - bit[i] ];
                ans += 1 << i;
            } else 
                root = root->child[bit[i]];
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int n : nums) 
            trie.insert(n);
        int ans = 0;
        for(int n : nums)
            ans = max(ans, trie.maxXor(n));
        return ans;
            
    }
};
