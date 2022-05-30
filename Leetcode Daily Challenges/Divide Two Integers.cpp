using ll = long double;
class Solution {
public:
    int divide(int dividend, int divisor) {
        ll result=0;
        int sign = 1;
        if(dividend<0) sign *= -1;
        if(divisor<0) sign *= -1;
        if(divisor == 1 || dividend ==0) return dividend;
        
        ll a = dividend;
        ll b = divisor;
        
        if(a<0) a = abs(a);
        
        if(b<0) b = abs(b);
        
        if(a<b) return 0;
        result = exp(log(a) - log(b));
        if(result < INT_MIN || result > INT_MAX) return INT_MAX;
        return sign*result;
    }
};
