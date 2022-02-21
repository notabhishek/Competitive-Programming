class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = -1, v = 1;
        for(int i : nums) {
            if(e != i) v--;
            else ++v;
            if(v == 0) {
                e = i; 
                v = 1;
            }
        }
        return e;
    }
};
