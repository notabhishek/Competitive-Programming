// Problem: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Solution 1: using multiset O(NlogN)
// Solution 2: using MaxDeque and MinDeque O(N)

// Solution 1: using multiset O(NlogN)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int i = 0, j = 0, n = nums.size();
        int ans = 0;
        while(i < n) {
            int diff = 0;
            while(j < n && diff <= limit) {
                window.insert(nums[j]);
                diff = (*window.rbegin()) - (*window.begin());
                ++j;
            }
            if(diff > limit) {
                --j;
                window.erase(window.find(nums[j]));
                diff = (*window.rbegin()) - (*window.begin());
            }
            if(diff <= limit) ans = max(ans, j - i);
            window.erase(window.find(nums[i]));
            ++i;
        }
        return ans;
    }
};

// Solution 2: using MaxDeque and MinDeque O(N)
// pre-requisite: https://github.com/notabhishek/Competitive-Programming/blob/main/Interview%20Prep/Google/Sliding%20Window%20Maximum.cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        deque<int> maxDeque, minDeque; // to maintain max, min of current window
        
        int ans = 1;
        int i = 0, j = 0, n = nums.size(); // minDeque index
        int diff = 0;
        while(i < n-1) {
            
            // expand current window until difference > limit
            while(j < n && diff <= limit) {
                while(!maxDeque.empty() && nums[maxDeque.back()] <= nums[j]) {
                    maxDeque.pop_back();
                }
                maxDeque.push_back(j);

                // push in minDeque
                while(!minDeque.empty() && nums[minDeque.back()] >= nums[j]) {
                    minDeque.pop_back();
                }
                minDeque.push_back(j);
                diff = nums[maxDeque.front()] - nums[minDeque.front()];
                if(diff <= limit) ans = max(ans, j-i+1);
                ++j;
            }
            // now diff > limit, erase i
            if(maxDeque.front() == i) maxDeque.pop_front();
            if(minDeque.front() == i) minDeque.pop_front();

            diff = nums[maxDeque.front()] - nums[minDeque.front()];
            ++i;
        }
        return ans;
    }
};
