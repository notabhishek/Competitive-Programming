class Trie{
    bool isLeaf;
    vector<Trie*> children;
public: 
    Trie() {
        isLeaf = false;
        children.assign(26, NULL);
    }
    
    void insert(string &s) {
        Trie *root = this;
        for(char c : s) {
            if(!root->children[c-'a'])
                root->children[c-'a'] = new Trie();
            root = root->children[c-'a'];
        }
        root->isLeaf = true;
    }
    
    bool isPrefix(string &s) {
        Trie *root = this;
        for(char c : s) {
            if(!root->children[c-'a']) return false;
            root = root->children[c-'a'];
        }
        return true;
    }
    
    bool suffixInTrie(string &s) {
        Trie *root = this;
        for(int i = s.length()-1; i >= 0; --i) {
            if(!root->children[s[i]-'a']) break;
            root = root->children[s[i]-'a'];
            if(root->isLeaf) return true;
        }
        return false;
    }
};
class StreamChecker {
public:
    Trie trie;
    string s;
    StreamChecker(vector<string>& words) {
        s = "";
        for(string &word : words) {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
    } 
    
    bool query(char letter) {
        s += letter;
        return trie.suffixInTrie(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
