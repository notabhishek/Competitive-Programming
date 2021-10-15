// Solution1: Multiset nlogk
// Solution2: Heap: nlogn 
// Solution3: MaxDeque: n

/*
// Solution 1
// Multiset solution: NlogK
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
*/

/*
// Solution 2
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
*/
