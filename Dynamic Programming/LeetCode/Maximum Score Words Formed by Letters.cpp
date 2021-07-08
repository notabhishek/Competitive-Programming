class Solution {
public:
    vector<string> w;
    vector<int> s;
    int f(int i, vector<int> l) {
        if( i < 0)
            return 0;
        int ans = f(i-1, l);
        // try making ith word
        int cur = 0;
        bool flag = true;
        vector<int> nl= l;
        for(auto &j : w[i]) {
            if(nl[j - 'a'] > 0) {
                cur += s[j-'a'];
                --nl[j-'a'];
            } else {
                flag = 0;
                break;
            }
        }
        if(flag)
            ans = max(ans , cur + f(i-1, nl));
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        w = words;
        s = score;
        vector<int> l(26,0);
        for(auto &i : letters) l[i-'a']++;
        return f(w.size()-1 , l);
    }
};
