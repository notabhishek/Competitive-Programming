class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> fp(26,0);
        for(char c : p) 
            fp[c-'a']++;
        int np = p.length(), ns = s.length();
        vector<int> fs(26,0);
        vector<int> res;
        if(ns < np) return res;
        for(int i = 0; i < np-1; ++i)
            fs[s[i]-'a']++;
        for(int i = np-1; i < ns; ++i) {
            fs[s[i]-'a']++;
            if(fp == fs) res.push_back(i+1 - np);
            fs[s[i+1-np]-'a']--;
        }
        return res;
    }
};
