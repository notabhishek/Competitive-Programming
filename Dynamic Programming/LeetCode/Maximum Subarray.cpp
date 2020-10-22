class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        // O(n) solution 
        int ans = nums[0] , cs = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(cs < 0) 
                cs = 0;
            cs+= nums[i];
            ans = max(ans , cs);
        }
        return ans;
        
        // Divide and Conquer
        // Can be done by storing prefix , suffix , sum at each node and merging
        // same as we do in seg tree
    }
};