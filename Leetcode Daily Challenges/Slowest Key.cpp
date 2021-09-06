class Solution {
public:
    char slowestKey(vector<int>& a, string s) {
        int t = a[0];
        char c = s[0];
        for(int i = 1; i < s.length(); ++i) {
            if(a[i] - a[i-1] > t) {
                t = a[i] - a[i-1];
                c = s[i];
            } else if(a[i]-a[i-1] == t) {
                c = max(c, s[i]);
            }
        }
        return c;
    }
};
