/**
 * @type of st: stack of integers
 * @return type: stack of integers
 */
class Solution {
public:
    stack<int> sortStack(stack<int>& st) {
   		// write your awesome code here
        int n = st.size();
        stack<int> aux;
        for(int round = 0; round < n; ++round) {
        	// pop n-round elements
        	int mx = st.top();
            for(int i = round; i < n; ++i) {
            	mx = max(st.top(), mx);
                aux.push(st.top());
                st.pop();
            }
            st.push(mx);
            while(!aux.empty()){
                if(mx == aux.top()) {
                	aux.pop();
                    mx = INT_MAX;
                    continue;
                }
            	st.push(aux.top());
                aux.pop();
            }
        }
        return st;
    }
};
