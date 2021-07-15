class Solution {
public:
    int S;
    bool dfs(int i , int sum1 , int sum2 , int sum3 , int sum4, vector<int> &nums) {
        if(sum1 > S || sum2 > S || sum3> S || sum4 > S)
            return false;
        if(i==0) {
            if(sum1 == sum2 && sum3==sum4 && sum2==sum3)
                return true;
            return false;
        }
        if(dfs(i-1 , sum1 + nums[i-1] , sum2 , sum3, sum4 ,nums)) 
            return true;
        if(dfs(i-1 , sum1 , sum2+nums[i-1] , sum3, sum4 , nums )) 
            return true;
        if(dfs(i-1 , sum1 , sum2 , sum3 + nums[i-1], sum4 , nums)) 
            return true;
        if(dfs(i-1 , sum1 , sum2 , sum3, sum4 + nums[i-1] , nums )) 
            return true;
        return false;        
    }
    bool makesquare(vector<int>& nums) {
        
        if(nums.size()==0)
            return false;
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum%4!=0)
            return false;
        sum/=4;
        S = sum;
        return dfs(nums.size() , 0 , 0 , 0 , 0, nums);
    }
};
