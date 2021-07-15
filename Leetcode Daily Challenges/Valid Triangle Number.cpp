class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n = a.size();
        sort(a.begin() , a.end());
        int nz = n - count(a.begin() , a.end() , 0);
        int ans = (nz * (nz-1) * (nz-2) )/6;
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j+1 < n; ++j) {
                if(a[i] == 0 || a[j] == 0) continue;
                int id = lower_bound(a.begin() , a.end() , a[i] + a[j]) - a.begin();
                // cout << i << " " << j << " " << id << endl;
                ans -= n-id;
            }
        }
        return ans;
    }
};
