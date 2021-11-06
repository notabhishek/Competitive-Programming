class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int allxor = accumulate(nums.begin(), nums.end(), 0ll, [](unsigned int u,int v){
            return u^v;
        });
        int bit = allxor & -allxor;
        int xor1 = 0;
        for(int i : nums) {
            if(i&bit) xor1 ^= i;
        }
        return {xor1, (int)(allxor ^ xor1)};
    }
};
