/**
 * @type of s: string
 * @return type: integer
 */
class Solution {
public:
    int checkParentheses(string s) {
   		// write your awesome code here
        stack<char> Stack;
        for(char c: s) {
        	if(c == '(' || c == '[' || c == '{') Stack.push(c);
            else {
            	if(( c==')' && Stack.top()=='(' ) || 
                   ( c==']' && Stack.top()=='[' ) || 
                   ( c=='}' && Stack.top()=='{' )) Stack.pop();
                else return 0;
            }
        }
        return Stack.size() == 0;
    }
};
