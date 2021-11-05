/**
 * @type of arr: integer array
 * @return type: integer array
 */
class Solution {
public:
    vector<int> findNextGreater(vector<int>& arr) {
   		// write your awesome code here
        int n = arr.size();
        stack<int> st;
        vector<int> RGE(n, -1); 
        for(int i = 0; i < n; ++i) {
        	if(st.empty() || arr[st.top()] >= arr[i]) 
                st.push(i);
            else {
            	while(!st.empty() && arr[st.top()] < arr[i]) {
                	RGE[st.top()] = arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return RGE;
    }
};
