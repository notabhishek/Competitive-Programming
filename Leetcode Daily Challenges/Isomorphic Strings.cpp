class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        map< char , char> m , rm;
        for(int i = 0; i < s.length(); ++i) {
            if(m.count(s[i])) {
                if(m[s[i]] != t[i])
                    return false;
            } else {
                if(rm.count(t[i])) return false;
                rm[t[i]] = s[i];
                m[s[i]] = t[i];
            }
        }
        return true;
    }
};
