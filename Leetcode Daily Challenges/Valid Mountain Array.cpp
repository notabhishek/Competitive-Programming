class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0, n = arr.size();
        if(n < 3) return false;
        while(i < n-1 && arr[i] < arr[i+1]) ++i;
        if(i == 0 || i == n-1) return false;
        while(i < n-1 && arr[i] > arr[i+1]) ++i;
        return i == n-1;
    }
};
