https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem
#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int MX_DIG = 19;
ll dp[MX_DIG][2][2];
ll recur(string &L, string &R, int n, bool lt, bool rt) {
    if(n==0) return 1;
    if(dp[n][lt][rt] != -1)
        return dp[n][lt][rt];
        
    int lb = lt ? L[L.length()-n]-'0' : 0;
    int ub = rt ? R[R.length()-n]-'0' : 9;
    ll answer = 0;
    for(int dig = lb; dig <= ub; ++dig) {
        if(dig % 2 != (L.length()-n)%2)
            answer += recur(L, R, n-1, lt & (dig==lb), rt & (dig==ub));
    } 
    return dp[n][lt][rt] = answer;
}
void solve() {
    ll L, R;
    cin >> L >> R;
    string prevL = to_string(L), strR;
    ll nxtR = 1;
    for(int i = 0; i < prevL.length(); ++i)
        nxtR *= 10;
    ll answer = 0, cans;
    while(nxtR-1 < R) {
        strR = to_string(nxtR-1);
        memset(dp, -1, sizeof dp);
        cans = recur(prevL, strR, strR.length(), 1, 1);
        answer += cans;
        prevL = to_string(nxtR);
        nxtR *= 10;
    }
    strR = to_string(R);
    memset(dp, -1, sizeof dp);
    cans = recur(prevL, strR, strR.length(), 1, 1);
    answer += cans;
    cout << answer << "\n";
}
int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
