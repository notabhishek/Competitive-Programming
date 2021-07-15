class Solution {
public:
    bool chk(vector<int> &a ,long long int s , int m){
        int k = 0;
        for(int i = 0; i < a.size();) {
            long long int cs = 0;
            if(a[i] > s) 
                return false;
            while(i < a.size() && cs + a[i] <= s) {
                cs+= a[i];
                ++i;
            }
            ++k;
        }
        return (k <= m);
    }
    int splitArray(vector<int>& nums, int m) {
        long long int lo = 0 , hi = accumulate(nums.begin() , nums.end() , 0ll);
        long long int ans;
        while(lo <= hi) {
            long long int mid = (lo + hi)/2;
            bool v = chk(nums , mid , m);
            if( v == false) lo = mid+1;
            else {
                ans = mid;
                hi = mid -1;
            }
        }
        return ans;
    }
};
