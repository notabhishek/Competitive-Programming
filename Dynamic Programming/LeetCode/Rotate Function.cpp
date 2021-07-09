class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        // 0a0 + 1a1 + 2a2 + 3a3 + .. . . + an-2  + an-1
         //want//  0an-1    1a0 2a1  3a2                       n-1an-2 
    // have  nan-1 extra
        int n = a.size();
        int ans;
        int cur = 0;
        int sum = accumulate(a.begin() , a.end(), 0);
        for(int i = 0 ; i < n; ++i)
            cur += i * a[i];
        ans = cur;
        for(int i = 1; i < n; ++i) {
            ans = max(cur, ans);
            cur += sum;
            cur -= n * a[n-i];
        }
        ans = max(ans, cur);
        return ans;
    }
};
