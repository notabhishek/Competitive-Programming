/**
 * @type of num: unsigned integer
 * @return type: unsigned integer
 */
class Solution {
public:
    unsigned int reverseBits(unsigned int num) {
   		// write your awesome code here
        int lg = log2(num);
        unsigned int ans = 0;
        for(int i = 0; i <= lg; ++i) {
        	if(num & (1<<i)) ans ^= (1 << (lg-i));
        }
        return ans;
    }
};
