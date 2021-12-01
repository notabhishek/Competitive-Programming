class Solution {
public:
    int rob(vector<int>& nums) {
        int rob0 = 0, rob1 = 0;
        for(int i : nums) {
            int rob2 = max(rob0 + i, rob1);
            rob0 = rob1;
            rob1 = rob2;
        }
        return rob1;
    }
};
