class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0, sum = 0;
        for(int i : nums) {
            sum += i;
            mn = min(mn, sum);
        }
        return -mn + 1;
    }
};
