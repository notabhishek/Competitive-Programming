class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() == 1)
            return 0;
        int minP = INT_MAX;
        int ind = -1;
        for(int i = 1 ; i < arr.size(); ++i) {
            if((arr[i]* arr[i-1]) <= minP) {
                minP = arr[i] * arr[i-1];
                ind = i-1;
            }
        }
        cout << ind << " " << minP << endl;
        vector<int> a(arr.size()-1);
        for(int i = 0 ; i <= ind; ++i)
            a[i] = arr[i];
        for(int i = ind+2; i< arr.size(); ++i)
            a[i - 1] = arr[i];
        a[ind] = max(arr[ind] , arr[ind+1]);
        return minP + mctFromLeafValues(a);
    }
};
