class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1, hi = 1e9 + 10;
        while( lo <= hi ) {
            int mid = (lo + hi)/2;
            int time = 0;
            for(int p : piles) 
                time += (p + mid-1)/mid;
            if(time > h) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi + 1;
    }
};
