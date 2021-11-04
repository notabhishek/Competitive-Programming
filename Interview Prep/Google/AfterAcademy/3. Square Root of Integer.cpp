/**
 * @type of num: integer
 * @return type: integer
 */
class Solution {
public:
    int intSqrt(int num) {
        // write your awesome code here
        int lo = 0, hi = num;
        while(lo <= hi) {
         	int mid = lo + ((hi-lo)>>1);
            if((num/mid) >= mid) {
             	lo = mid + 1;   
            } else {
            	hi = mid - 1;
            }
        }
        return lo-1;
    }
};
