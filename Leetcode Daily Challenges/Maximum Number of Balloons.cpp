class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> f1(26,0), f2(26, 0);
        const string pat = "balloon";
        for(char i : pat) f1[i-'a']++;
        for(char i : text) f2[i-'a']++;
        int ans = INT_MAX;
        for(int i = 0; i < 26; ++i) {
            if(f1[i]) ans = min(ans, f2[i]/f1[i]);
        }
        return ans;
    }
};
