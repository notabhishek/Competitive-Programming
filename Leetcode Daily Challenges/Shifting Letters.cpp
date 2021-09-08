class Solution {
public:
    string shiftingLetters(string s, vector<int>& a) {
        int n = a.size();
        for(int i = n-2; i>=0; --i) a[i] = (a[i+1]%26 + a[i])%26;
        for(int i = 0; i < n; ++i) {
            s[i] ='a'  + (s[i]-'a'+ a[i]%26)%26;
        }
        return s;
    }
};
