class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n), suf(n);
        pre[0] = a[0];
        for(int i = 1; i < n; ++i) pre[i] = max(a[i], a[i] + pre[i-1]);
        suf[n-1] = a[n-1];
        for(int i = n-2; i >= 0; --i) suf[i] = max(a[i], a[i] + suf[i+1]);
        int ans = a[0];
        for(int i = 0; i < n; ++i) {
            ans = max(ans, max(pre[i], suf[i]));
            // delete ith element
            if(i > 0 || i < n-1)
            ans = max(ans, (i>0 ? pre[i-1] : 0) + (i < n-1 ? suf[i+1] : 0));
        }
        return ans;
    }
};
