class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        unordered_set<int> s;
        for(auto &i : a) s.insert(i);
        int ans = 0, n = a.size();
        for(int i =0 ; i < n; ++i) {
            for(int j = i +1; j < n; ++j) {
                int u = a[i] , v = a[j];
                int len = 2;
                while(s.find(u+v) != s.end()){
                    v = v + u;
                    u = v - u;
                    ++len;
                }
                ans= max(ans, len);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
