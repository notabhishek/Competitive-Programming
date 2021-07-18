// To avoid double counting use  < for LLE and <= for RLE
class Solution {
public:
    // Index of first element on left < a[i]
    void LLE(vector<int> &a, vector<int> &lle){
        int n = a.size();
        stack< int > s;
        for(int i = 0; i < n; ++i) {
            if(s.empty() || a[s.top()] < a[i]) {
                lle[i] = s.empty() ? -1 : s.top();
                s.push(i);
            } else {
                while(!s.empty() && a[s.top()] >= a[i]) {
                    s.pop();
                }
                lle[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
        }
    }
    
    // Index of first element on right <= a[i]
    void RLE(vector<int> &a, vector<int> &rle) {
        int n =a.size();
        stack<int> s;
        for(int i = n-1; i >= 0; --i) {
            if(s.empty() || a[s.top()] < a[i]) {
                rle[i] = s.empty() ? -1 : s.top();
                s.push(i);
            } else {
                while(!s.empty() && a[s.top()] > a[i]) {
                    s.pop();
                }
                rle[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
        }
    }
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<int> rle(n) , lle(n);
        LLE(a, lle);
        RLE(a, rle);
        int ans = 0;
        for(int i = 0; i < n; ++i)  {
            long long cur = ( (i - lle[i])*(rle[i]==-1 ? n-i : rle[i] - i))%MOD;
            cur = (cur * a[i]) %MOD;
            ans = (ans + cur ) % MOD;
        }
        return ans;
    }
};
