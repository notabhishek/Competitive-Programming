/**
 * @type of num: string
 * @return type: string
 */
class Solution {
public:
    string mirror(string s){
    	reverse(s.begin(), s.end());
        return s;
    }
    string nearestPalindrome(string num) {
        // write your awesome code here
       	int n = num.length();
        long long intNum = stoll(num);
        
        string half = num.substr(0, (n+1)/2);
        long long c1 = stoll(half + mirror(half.substr(0, n/2)));
     	int intHalf = stoll(half);
        
        string thlf = to_string(intHalf-1);
        
        long long c2;
        if(thlf.length() < half.length()) {
            c2 = stoll(string(n - 1, '9'));
        } else {
            c2 = stoll(thlf + mirror(thlf.substr(0, n/2)));
        }
        
        
        thlf = to_string(intHalf+1);
        long long c3 = stoll(thlf + mirror(thlf.substr(0, n/2)));
   		
        if(intNum >= 10 && intNum < 20) {
            c2 = 9;
        }
        
        long long ans = LLONG_MAX, diff = LLONG_MAX;
        long long newdiff;
        newdiff = abs(c3-intNum);
        if(c3 != intNum && newdiff <= diff) {
            if(newdiff < diff) ans = c3;
            else ans = min(c3, ans);
            diff = abs(c3-intNum);
        }
        newdiff = abs(c1-intNum);
        if(c1 != intNum && newdiff <= diff) {
        	if(newdiff < diff) ans = c1;
            else ans = min(c1, ans);
            diff = abs(c1-intNum);
        }
        newdiff = abs(c2-intNum);
        if(c2 != intNum && newdiff <= diff) {
        	if(newdiff < diff) ans = c2;
            else ans = min(c2, ans);
            diff = abs(c2-intNum);
        }
        return to_string(ans);
    }
};
