class Solution {
public:
    void add (int i ,string &s, vector<vector<string>> &SENT, vector<bool> &calc, unordered_set<string> &dict) {
        if(calc[i])
            return;
        calc[i] = 1;
        string word = "";
        for(int j = i; j < s.length(); ++j) {
            word+=s[j];
            if(dict.find(word)!=dict.end()) {
                add(j+1 ,s , SENT,calc ,  dict);
                if(j+1 == s.size())
                    SENT[i].push_back(word);
                else 
                    for(auto &x : SENT[j+1]) {
                        SENT[i].push_back(word + " " + x);
                    }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<bool> calc(s.size() + 1 , 0);
        vector<string> sent;
        vector<vector<string>> SENT(s.size()+1);
        for(auto &i : wordDict) dict.insert(i);
        calc[s.size()] = 1;
        SENT[s.size()].push_back("");
        add( 0 , s , SENT , calc, dict);
        return SENT[0];
    }
};
