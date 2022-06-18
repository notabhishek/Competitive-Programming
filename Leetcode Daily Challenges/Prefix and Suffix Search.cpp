class WordFilter {
    unordered_map<string, int> idx;
public:
    WordFilter(vector<string>& words) {
        for(int w = 0; w < words.size(); ++w) {
            int n = words[w].length();
            for(int i = 0; i < n; ++i) {
                string pref = words[w].substr(0, i+1) + "#";
                for(int j = 0; j < n; ++j) {
                    idx[pref + words[w].substr(j)] = w+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return idx[prefix + "#" + suffix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
