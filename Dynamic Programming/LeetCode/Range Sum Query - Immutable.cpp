class NumArray {
public:
    vector< int > pre;
    NumArray(vector<int>& nums) {
        pre.resize(nums.size() + 1 , 0);
        for(int i = 0; i < nums.size(); ++i) 
            pre[i + 1] = pre[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return pre[j + 1] - pre[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */