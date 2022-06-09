class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size()-1; ++i) {
            int x = target - numbers[i];
            int hi = numbers.size()-1 , lo = i+1;
            while(lo<=hi) {
                int mid = (hi+lo)/2;
                if(numbers[mid] == x) {
                    vector<int> v{i+1 , mid+1};
                    return v;
                } else if(numbers[mid] > x) hi = mid-1;
                else lo = mid+1;
            }
        }
        vector<int> v;
        return v; 
    }
};
