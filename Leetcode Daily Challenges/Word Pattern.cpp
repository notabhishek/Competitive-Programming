class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> m(26, "");
        int i = 0, n = s.length();
        unordered_map<string, char> wcMap;
        for(char c : pattern) {
            string w = "";
            while(i < n && s[i] != ' ')
                w += s[i++];
            if(w == "") return false;
            if((m[c-'a']!="" && m[c-'a'] != w) || (wcMap.count(w) > 0 && wcMap[w] != c))
                return false;
            m[c-'a'] = w;
            wcMap[w] = c;
            ++i;
        }
        return i >= n;
    }
};
