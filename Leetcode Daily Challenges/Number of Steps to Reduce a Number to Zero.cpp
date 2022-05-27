class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num != 0) {
            if(num&1) num^=1;
            else num>>=1;
            ++ans;
        }
        return ans;
    }
};
