class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int i : nums) {
            if(m.count(i)) {
                if(m[i] == 1) 
                    m.erase(i);
                else 
                    m[i]--;
                ++ans;
            } else 
                m[k-i]++;
        }
        return ans;
    }
};
