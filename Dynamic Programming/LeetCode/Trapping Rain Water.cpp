class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int n = height.size();
        int lbig[n] , rbig[n];
        rbig[n-1] = height[n-1];
        for(int i = n-2; i>=0; --i) {
            rbig[i] = max(height[i] , rbig[i+1]);
        }
        lbig[0] = height[0];
        for(int i = 1; i < n; ++i) {
            lbig[i] = max(lbig[i-1] , height[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < n;++i) {
            ans+= min(lbig[i] , rbig[i]) - height[i];
        }
        return ans;
    }
};
