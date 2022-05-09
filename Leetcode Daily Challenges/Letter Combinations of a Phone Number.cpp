class Solution {
    vector<string> l{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
public:
    void rec(int i, string &d, string &cur) {
        if(i == d.length()) {
            res.push_back(cur); 
            return;
        } 
        for(char c : l[d[i]-'0']) {
            cur += c;
            rec(i+1, d, cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return res;
        res.clear();
        string cur = "";
        rec(0, digits, cur);
        return res;
    }
};
