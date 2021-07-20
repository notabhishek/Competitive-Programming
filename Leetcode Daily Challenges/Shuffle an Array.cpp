class Solution {
public:
    vector<int> a;
    vector<int> b;
    Solution(vector<int>& nums) {
        a = nums;
        b = a;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < a.size(); ++i) {
            int u = rand() % a.size();
            int v = rand() % a.size();
            if(rand() & 1)
            swap(b[u] , b[v]);
        }
        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
