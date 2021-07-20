class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        DP[i] = length of valid substring ending at i 
        2 cases 
            1.  validSubstring + ()
            2. validSubstring1 ( validSubstring2 )
        */
        // int n = s.length();
        // vector<int> dp( n, 0);
        // int ans = 0;
        // for(int i = 1; i < n; ++i) {
        //     if(s[i] == ')') {
        //         // case1   substr ()
        //         if(s[i-1] == '(') dp[i] = max(dp[i] , 2 + (i>1 ? dp[i-2] : 0));
        //         // case2   ( substr )
        //         int idx = i - dp[i-1] - 1;
        //         if(s[i-1] == ')' && idx>=0 && s[idx] == '(') {
        //             int cur = 2 + dp[i-1] + ( idx > 0 ? dp[idx-1] : 0);
        //             dp[i] = max(dp[i], cur); 
        //         }
        //         ans = max(ans, dp[i]);
        //     }
        // }
        
        
        /*
        Stack approach
        1. push (
        2. ) -> pop 1 ( and  ans = max(ans, st.top() - i)
        */
        int n = s.length() , ans = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if(st.empty()) {
                   st.push(i); 
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};
