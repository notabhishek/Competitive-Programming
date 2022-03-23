class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue) {
            ++ans;
            (target&1) ? ++target : target/=2; 
        }
        return ans + startValue - target;
    }
};
