class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
       	// using stack to find next, prev smaller values for every i
        stack<int> Stack; // stores indexes in non-descreasing order of height
        int i = 0, n = arr.size();
        while( i < n ) {
        	if(Stack.empty() || arr[Stack.top()] <= arr[i])	
                Stack.push(i++);
           	else {
             	int tp = Stack.top();
                Stack.pop();
                if(Stack.empty()) { // no smaller element to left
                	maxArea = max(maxArea, arr[tp] * i);
                } else { // smaller to left = Stack.top(), smaller to right = i
                    maxArea = max(maxArea, arr[tp] * (i - Stack.top()-1));
                }
            }
        }
        while(!Stack.empty()) {
            int tp = Stack.top();
            Stack.pop();
            if(Stack.empty()) { // no smaller element to left
                maxArea = max(maxArea, arr[tp] * i);
            } else { // smaller to left = Stack.top(), smaller to right = i
                maxArea = max(maxArea, arr[tp] * (i - Stack.top()-1));
            }
        }
        return maxArea;
    }
};
