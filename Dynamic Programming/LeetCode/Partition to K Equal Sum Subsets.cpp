class Solution {
public:
    bool rec(vector<int> &a, int sum) {
        // for(auto &i : a) cout << i << " "; cout << endl;
        if(a.size() == 0)
            return true;
        int n = a.size();
        for(int i = 0; i < (1<<n); ++i) {
            int cur = 0;
            for(int j = 0; j < n; ++j) 
                if(i & (1<<j)) cur += a[j];
            if(cur == sum) {
                vector<int> b;
                for(int j = 0; j < n; ++j) 
                    if(!(i & (1<<j)))
                        b.push_back(a[j]);
                if(rec(b, sum)) return true;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum % k  != 0)
            return false;
        return rec(a, sum/k);
    }
};
