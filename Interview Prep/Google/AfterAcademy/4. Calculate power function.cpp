/**
 * @type of k: integer
 * @type of n: unsigned integer
 * @return type: integer
 */
class Solution {
public:
    int fpow(int k,unsigned int n) {
     	if(n == 0) return 1;
        int x = fpow(k, n/2);
        x *= x;
        if(n&1) x *= k;
        return x;
    }
	int calculatePower(int k, unsigned int n) {
		// write your awesome code here
        return fpow(k, n);
	}
};
