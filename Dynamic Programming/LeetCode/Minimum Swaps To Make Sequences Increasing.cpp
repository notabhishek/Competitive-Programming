class Solution {
public:
    const int INF = 1e7;
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int s0 = 0, s1 = 1; // s0 = swaps required till i, s.t. nums1[i] stays at i, s1 => nums1[i] and nums2[i] have been swapped
        for(int i = 1; i < nums1.size(); ++i) {
            int news0 = INF, news1 = INF;
            if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) news0 = min(news0, s0);
            if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) news0 = min(news0, s1);
            
            if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]) news1 = min(news1, 1 + s0);
            if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]) news1 = min(news1, 1 + s1);
            
            s0 = news0;
            s1 = news1;
        }
        return min(s0, s1);
    }
};
