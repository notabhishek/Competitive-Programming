class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> rpos(26, 0);
        int n = s.size();
        for(int i = 0; i < n; ++i) 
            rpos[s[i] - 'a'] = i;
        int st = 0;
        vector<int> ans;
        while(st < n) {
            int len = 1, en = rpos[s[st]-'a'];
            while(st < en) {
                ++st, ++len;
                en = max(en, rpos[s[st]-'a']);
            }
            ans.push_back(len);
            ++st;
        }
        return ans;
    }
};
