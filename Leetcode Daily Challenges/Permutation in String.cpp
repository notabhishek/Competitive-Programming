class Solution {
public:
    bool checkInclusion(string a, string b) {
        vector<int> fa(26, 0), fb(26, 0);
        int n = a.length(), m = b.length();
        if(m < n) return false;
        for(int i = 0; i < n-1; ++i) 
            fa[a[i]-'a']++, fb[b[i]-'a']++;
        
        fa[a[n-1]-'a']++;
        for(int i = n-1; i < m; ++i) {
            fb[b[i]-'a']++;
            if(fb == fa) return true;
            fb[b[i+1-n]-'a']--;
        }
        return false;
    }
};
