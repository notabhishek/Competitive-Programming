class WordDictionary {
public:
    /** Initialize your data structure here. */
    bool isLeaf;
    vector<WordDictionary*> next;
    WordDictionary() {
        isLeaf = false;
        next.resize(26 , nullptr);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *root = this;
        for(auto &i : word) {
            if( root->next[i-'a'] == nullptr ) 
                root ->next[i-'a'] = new WordDictionary();
            root = root->next[ i-'a' ];
        }
        root->isLeaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchUtil(int ind ,WordDictionary *root ,string word) {
        if(ind == word.size()-1) { //Base case check leaf
            if(word[ind]  == '.') {
                for(int i = 0 ; i < 26; ++i)
                    if(root->next[i] && root->next[i]->isLeaf)
                        return true;
                return false;
            } else {
                return root->next[word[ind] - 'a'] && root->next[word[ind] - 'a']->isLeaf;
            }
        }
        if(word[ind] == '.') {
            for(int j = 0 ; j < 26; ++j) 
                    if(root->next[j] && searchUtil(ind+1 ,root->next[j] , word))
                        return true;
                return false;
        } else {
            return root->next[ word[ind]-'a' ] && searchUtil(ind+1 , root->next[ word[ind]-'a' ] , word);
        }
        return true;
    }
    bool search(string word) {
        return searchUtil(0 ,this ,  word);
    }
};
