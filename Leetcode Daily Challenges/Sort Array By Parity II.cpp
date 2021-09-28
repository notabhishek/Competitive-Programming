class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int ptr[2] = {0, 1};
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]%2 == i%2) continue;
            int j = 1-(i%2); 
            while(nums[ptr[j]]%2 != i%2) ptr[j]+=2;
            swap(nums[i], nums[ptr[j]]);
        }
        return nums;
    }
};
