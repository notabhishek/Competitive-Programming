class Solution {
public:
    bool isSubseq(string &a, string &b) { // check if a is subseq of b
        int i = 0, j = 0;
        while(i < a.length() && j < b.length()) {
            if(a[i] == b[j]) ++i, ++j;
            else ++j;
        }
        return i == a.length();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string &a, string &b){
            return a.length() > b.length();
        });
        for(int i = 0; i < strs.size(); ++i) {
            bool f = 1;
            for(int j = 0; j < strs.size() && strs[j].length() >= strs[i].length(); ++j) 
                if(i!=j && isSubseq(strs[i], strs[j])) {
                    f = 0; break;
                }
            if(f) return strs[i].length();
        }
        return -1;
    }
};
