/**
 * @type of num1: integer
 * @type of num2: integer
 * @return type: integer
 */
class Solution {
public:
    int findGCD(int num1, int num2) {
   		// write your awesome code here
        if(num1 < num2) swap(num1, num2);
        if(num2 == 0) return num1;
        return findGCD(num2, num1 % num2);
    }
};
