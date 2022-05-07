class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 1 2 3 4
        stack< int > s;
        int second = INT_MIN;
        for(int i = nums.size()-1; i>=0; --i) {
            if(nums[i] < second) {
                return true;
            }
            while(!s.empty() && nums[i] > s.top() ) {
                second = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
