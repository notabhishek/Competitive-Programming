class Solution {
public:
    long long int kadane(vector<int> &arr) {
        long long int mx = 0 , cs = 0;
        for(auto &i : arr) {
            cs+=i;
            cs = max(cs , 0ll);
            mx = max(mx , cs);
        }
        return mx;
    }
    long long int pref(vector<int> &arr) {
        long long int mx = 0 , cs =0;
        for(auto &i : arr) {
            cs+=i;
            mx=max(mx , cs);
        }
        return mx;
    }
    long long int suff(vector<int> &arr) {
        long long int mx = 0, cs = 0;
        for(int i = arr.size()-1 ; i >=0 ; --i) {
            cs += arr[i];
            mx = max(mx , cs);
        }
        return mx;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int sum = accumulate(arr.begin() , arr.end() , 0ll);
        long long int ans1 = kadane(arr);
        long long int p = pref(arr);
        long long int s = suff(arr);
        // cout << "kadane : "<< ans1 << endl;
        if(k == 1)
            return ans1;
        long long int ans = ans1;
        ans = max(ans , s + p );
        ans = max(ans , sum + p);
        ans = max(ans , s + sum);
        ans = max(ans , 2*sum);
        if(k > 2) {
            ans = max(ans , s + (k-2)*sum + p );
        }
        const int mod = 1e9 + 7;
        return ans%mod;
    }
};
