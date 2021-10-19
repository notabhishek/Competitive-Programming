class Solution {
public:
    void RGE(vector<int> &arr, vector<int> &rge){
        stack<int> st;
        for(int i = 0; i < arr.size(); ++i){
            if(st.empty() || arr[i] <= arr[st.top()]){
                st.push(i);
            } else {
                while(!st.empty() && arr[st.top()] < arr[i]){
                    rge[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) {
            rge[st.top()] = -1;
            st.pop();
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rge(nums2.size());
        RGE(nums2, rge);
        // for(int i : rge) cout << i << " "; cout << endl;
        unordered_map<int,int> pos;
        for(int i = 0; i < nums2.size(); ++i) {
            pos[nums2[i]] = (rge[i]==-1 ? -1 : nums2[rge[i]]);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            ans[i] = pos[ nums1[i]];
        }
        return ans;
    }
};
