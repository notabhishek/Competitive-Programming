class Solution {
public:

    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> lis(n, 1);
        vector<int> cnt(n, 0);
        cnt[0] = 1;
        
        for(int i = 1; i < n ; ++i) {
            for(int j = 0; j < i; ++j) 
                if(a[i] > a[j])
                    lis[i] = max(lis[i] , 1 + lis[j]); 
            if(lis[i] == 1)
                cnt[i] = 1;
            for(int j = 0; j < i; ++j)
                if(a[i] > a[j] && lis[j] == lis[i]-1)
                    cnt[i] += cnt[j];
        }
        
        int L = *max_element(lis.begin() , lis.end()) , ans = 0;
        for(int i = 0; i < n; ++i) {
            if(lis[i] == L) ans += cnt[i];
        }
        return ans;
    }
};
