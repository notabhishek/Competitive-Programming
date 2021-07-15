class Solution {
public:

    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        if(s1 == s2)
            return true;
        int f[26] = {0};
        for(int i = 0 ; i < s1.length(); ++i) { 
            f[s1[i]-'a']++;
            f[s2[i]-'a']--;
        }
        for(int i = 0; i <26; ++i)
            if(f[i]!=0)
                return false;
        for(int i = 1; i < s1.length(); ++i) {
            string a = s1.substr(0 , i) , b = s1.substr(i);
            for(int j = 1; j < s2.length(); ++j) {
                string c = s2.substr(0 , j) , d = s2.substr(j);
                if(isScramble(a , c) && isScramble(b , d))
                    return true;
                if(isScramble(a , d) && isScramble(b , c))
                    return true;
            }
        }
        return false;
    }
};
