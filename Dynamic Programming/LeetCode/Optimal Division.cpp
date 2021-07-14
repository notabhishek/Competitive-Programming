class Solution {
public:
    /*
    To increase the value of p/q  we can 
        1.increase p( we can't)
        2.decrese q ( to do this we do not put brackets in q and solve it first)                            since p/q/r <= p/(q/r)
    */
    string optimalDivision(vector<int>& nums) {
        if( nums.size() == 1) 
            return to_string(nums[0]);
        if( nums.size() == 2) 
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string res = "";
        res += to_string(nums[0]) + "/(";
        for(int i = 1; i < nums.size()-1; ++i) {
            res += to_string(nums[i]) + "/";
        }
        res += to_string(nums.back()) + ")";
    
        return res;
    }
};
