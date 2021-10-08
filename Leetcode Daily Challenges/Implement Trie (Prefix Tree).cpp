class Trie {
public:
    /** Initialize your data structure here. */
    bool isLeaf;
    vector<Trie*> next;
    Trie() {
        isLeaf = false;
        next.resize(26 , nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = this;
        for(auto &i : word) {
            if(root->next[i-'a'] == nullptr)
                root->next[i-'a'] = new Trie();
            root = root->next[i-'a'];
        }
        root->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        for(auto &i : word) {
            if(root->next[i-'a'] == nullptr)
                return false;
            root = root->next[i-'a'];
        }
        return root->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        for(auto &i : prefix) {
            if(root->next[i-'a'] == nullptr)
                return false;
            root = root->next[i-'a'];
        }
        return true;
    }
};
