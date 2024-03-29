// Problem: https://leetcode.com/problems/sliding-window-maximum/
// Solution1: Heap: nlogn 
// Solution2: MaxDeque: n

// Solution 1
// By Implementing heap of pairs {data,index}: NlogN
struct heapNode {
	int data, index;
	heapNode(int d, int i) : data(d), index(i) {};	
};
class Heap {
	vector<heapNode> heap;
	public:
	void heapify(int i) {
		int big = i;
		if(2*i < heap.size() && heap[2*i].data > heap[big].data) {
			big = 2*i;
		}
		if(2*i+1 < heap.size() && heap[2*i + 1].data > heap[big].data) {
			big = 2*i + 1;
		}
		swap(heap[big], heap[i]);
		if(big != i) 
			heapify(big);
	}
	void percolate(int idx) {
		if(idx == 0) return; 
		if(heap[idx].data > heap[idx/2].data) {
			swap(heap[idx], heap[idx/2]);
			percolate(idx/2);
		} 
	}
	void insert(int d, int idx) {
		heap.push_back({d, idx});
		percolate(heap.size()-1);
	}
	int size() { return heap.size(); }
	heapNode pop() {
		heapNode top = heap[0];
		swap(heap[0], heap[ heap.size()-1 ]);
		heap.pop_back();
		heapify(0);
		return top;
	}
	heapNode top() {
		return heap[0];
	}
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Heap h;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < k-1; ++i) {
            h.insert(nums[i], i);
        }
        for(int i = k-1; i < n; ++i) {
            h.insert(nums[i], i);
            while(h.top().index <= i-k) h.pop();
            ans.push_back(h.top().data);
        }
        return ans;
    }
};


// Solution 2
// Using Max Deque: O(N)
class Solution {
public:
    /*
    maintain a maxDeque: 
        indexes are in increasing order but values are in decreasing order
        at any time max of window will be front of deque
        
        Algo: 
            1. pop elements from back of deque till they are <= current element (to maintain desc order)
            2. insert the current element 
            3. if the element at front of deque is out of bounds, pop_front()
            4. Max of the window = nums[maxDeque.front()]
            
        Complexity :
            Every element is pushed and popped only once, hence complexity O(N)
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxDeque; 
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            // pop elements from right until nums[right] < nums[i]
            while(!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) maxDeque.pop_back();
            
            // push the current element 
            maxDeque.push_back(i);
            
            // remove left element until it is out of bounds
            if(maxDeque.front() <= i-k) maxDeque.pop_front();
            
            // Maximum for this window: maxDeque.front()
            if(i >= k-1) ans.push_back(nums[maxDeque.front()]); 
        }
        return ans;
    }
};

