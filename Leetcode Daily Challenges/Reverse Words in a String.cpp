class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string word = "";
        for(int i = s.length()-1; i >= 0; --i){
            if(s[i] == ' ') {
                if(word!="") {
                    reverse(word.begin(), word.end());
                    res += (res == ""? word : " " + word);
                }
                word  = "";
            } else {
                word += s[i];
            }
        }
        if(word!="") {
            reverse(word.begin(), word.end());
            res += (res == ""? word : " " + word);
        }
        return res;
    }
};
