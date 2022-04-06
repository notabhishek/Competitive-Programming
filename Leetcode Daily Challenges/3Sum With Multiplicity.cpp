class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size(), mxSum = 300;
        const int mod = 1e9 + 7;
        vector<vector<int>> twoSum(n, vector<int>(mxSum+1, 0));
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < i; ++j) 
                twoSum[i][arr[i] + arr[j]]++;
        
        for(int i = 1; i < n; ++i) 
            for(int s = 0; s <= mxSum; ++s) 
                twoSum[i][s] += twoSum[i-1][s];
        
        long long int ans = 0;
        for(int i = 2; i < n; ++i) 
            if(target >= arr[i])
                ans = (ans + twoSum[i-1][target - arr[i]]) %mod;
        return ans % mod;
    }
};
