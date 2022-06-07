class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mergedIndex { m + n - 1};
        int larger;
	   
		 while(m && n) {
			 if( nums2[n - 1] > nums1[m - 1] ) larger = nums2[--n];
             else larger = nums1[--m];
             nums1[mergedIndex--] = larger;
		 }
         while(m) nums1[mergedIndex--] = nums1[--m];
         while(n) nums1[mergedIndex--] = nums2[--n];
    }
};
