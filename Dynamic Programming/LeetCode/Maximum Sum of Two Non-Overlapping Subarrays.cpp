class Solution {
public:
    int solve(vector<int>& A, int L, int M){
        vector<int> a(A.size() , 0) , b(A.size() , 0);
        int sum=0 , mx = 0;
        for(int i = 0 ; i < L-1; ++i) sum+= A[i];
        for(int i = L-1; i <A.size(); ++i) {
            sum+= A[i];
            a[i] = max(mx , sum);
            mx = max(mx , a[i]);
            sum-= A[i - L+1];
        }
        
        sum = 0;
        for(int i = 0 ; i < M-1; ++i) sum+= A[A.size()-1-i];
        mx = 0;
        for(int i = A.size()- M; i>=0; --i){
            sum+=A[i];
            b[i] = max(mx , sum);
            mx = max(mx , b[i]);
            sum-=A[i+M-1];
        }
        //for(auto i : a) cout << i << " " ; cout << endl;
        //for(auto i : b) cout << i << " " ; cout << endl;
        int ans = 0;
        for(int i = L-1; i < A.size() - M; ++i)
            ans = max(ans , a[i] + b[i+1]);
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(solve(A , L, M) , solve(A , M , L));
    }
};
