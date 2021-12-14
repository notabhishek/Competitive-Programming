template<typename T> ostream& operator << (ostream &os, const set<T> &s) {
    os << "[ ";
    for(const T &i : s) os << i << ", ";
    os << " ]\n";
    return os;
} 
class Solution {
public:
    void getSums(vector<int> &a, vector<int> &s) {
        int n = a.size(), N = 1<<n, sum;
        s.push_back(0);
        for(int m = 1; m < N; ++m) {
            sum = 0;
            for(int i = 0; i < n; ++i) {
                if(m&(1<<i)) sum += a[i];
            }
            s.push_back(sum);
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n2 = n/2;
        vector<int> v1(nums.begin(), nums.begin() + n2), v2(nums.begin()+n2, nums.end());
        vector<int> s1, s2;
        getSums(v1, s1);
        getSums(v2, s2);
        sort(s2.begin(), s2.end());
        int ans = abs(goal);
        for(const int &i : s1) {
            auto it = lower_bound(s2.begin(), s2.end(), goal - i);
            if(it != s2.end()) 
                ans = min(ans, *it+i-goal);
            if(it != s2.begin())
                ans = min(ans, goal-i-(*prev(it)));
        }
        return ans;
    }
};
