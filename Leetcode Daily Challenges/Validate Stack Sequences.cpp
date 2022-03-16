class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, j = 0 , n = pushed.size();
        while(i < n && j < n) {
            if(!s.empty() && popped[j] == s.top()) {
                ++j;
                s.pop();
            } else {
                s.push(pushed[i]);
                ++i;
            }
        }
        while(j < n) {
            if(s.top() != popped[j]) return false;
            s.pop(); ++j;
        }
        return true;
    }
};
