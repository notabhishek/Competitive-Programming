class Solution {
public:
    int calc(int n , vector<int> &steps ){
        if(steps[n]!=-1)
            return steps[n];
        steps[n] = INT_MAX;
        for(int i = 1; i < n; ++i) {
            if((n-i)%i == 0)
                steps[n] = min( steps[n] , calc(i , steps) + 1 + (n-i)/i );
        }
        return steps[n];
    }
    int minSteps(int n) {
        vector<int> steps(n+1 , -1);
        steps[1] = 0;
        calc(n , steps);
        for(auto i : steps ) cout << i  <<  " ";
        return steps[n];
    }
};
