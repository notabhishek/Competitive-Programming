class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        for(int bit = 0; bit <= 31; ++bit) {
            int c1 = 0, c2 = 0, xor1 = 0, xor2 = 0;
            for(int i : nums) {
                if(i&(1<<bit)) {
                    ++c1; xor1 ^= i;
                } else {
                    ++c2; xor2 ^= i;
                }
            }
            if(c1 & 1) return {xor1, xor2};
        }
        return {0, 0};
    }
};
