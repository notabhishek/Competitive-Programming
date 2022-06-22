class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums) {
            if(pq.size() == k && pq.top() < i) pq.pop();
            if(pq.size() < k) pq.push(i);
        }
        return pq.top();
    }
};
