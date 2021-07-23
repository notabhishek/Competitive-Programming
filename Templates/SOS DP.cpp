// Sum Over Subsets | Dynamic Programming
// given f values for some masks f[mask] = given
// compute SOS ( Sum over Subset ) of given mask
// i.e. given mask find sum(f[submask]) s.t.  submask & mask = submask
		
#include <bits/stdc++.h>
using namespace std;

// Approach 1 
// Time 	: 4^n
// Space 	: 2^n
void A1(int n, vector<int> &f) {
	vector<int> h(1 << n);
	for(int t = 0; t < (1<<n); t++) {
		h[t] = 0;
		for(int x = 0; x < (1<<n); ++x) {
			if((x&t) == x) 
				h[t] += f[x];
		}
	}
	for(int i = 0; i < (1<<n); ++i) {
		cout << h[i] << " ";
	}
	cout << "\n";
}

// Approach 2 : O(3^n) = nC1  * 2^1 + nC2* 2^2 + ....
// Complexity : first we chose k set bits then make 2^k subsets i.e sum(nCk * 2^k) = 3^k
// Time 	: 3^n
// Space 	: 2^n
void A2(int n, vector<int> &f) {
	vector<int> h(1 << n);
	for(int t = 0; t< (1<<n); ++t) {
		h[t] = 0;
		for(int x = t; x > 0; x = ((x-1) & t)) 
			h[t] += f[x];
		h[t] += f[0];
	}
	for(int i = 0; i < (1<<n); ++i) {
		cout << h[i] << " ";
	}
	cout << "\n";
}

// Approach 3 : using dp
/*
Time 	: n * 2^n
Space 	: n * 2^n
	 
dp[t][i] = 	ans for subsets where only first i bits 
			are allowed to be flipped
dp[11 101][3] = f(11 000) + f(11 001) + f(11 100) + f(11 101) 

Recurrence : 
	
	t&(1<<(i-1)) == 0, off bit
	dp[t][i] = dp[t][i-1]  , this bit has no effect on subsets
	
	t&(1<<(i-1)) > 0, on bit
	dp[t][i] = 	dp[t][i-1]  , ith bit is off in these subsets
				+
			   	dp[t ^ (1<<(i-1))][i-1], ith bit is on in these subsets
*/
void A3(int n, vector<int> &f) {
	// cout << f;
	vector<int> h(1 << n);
	
	int dp[ 1<<n ][ n+1 ]; 
	
	for(int t = 0; t < (1<<n); ++t) {
		dp[t][0] = f[t];
	}
	
	for(int t = 0; t < (1<<n); t++) {
		
		for(int i = 1; i <= n; ++i) {
			if((t & (1<<(i-1)))) {
				dp[t][i] = dp[t][i-1] + dp[t^(1<<(i-1))][i-1];
			} else {
				dp[t][i] = dp[t][i-1];
			}	
		}
	}
	
	for(int t = 0; t < (1<<n); ++t) {
		h[t] = dp[t][n];
	}

	for(int i = 0; i < (1<<n); ++i) {
		cout << h[i] << " ";
	}
	cout << "\n";
}
void solve()
{
	int n;
	cin >> n;
	vector<int> f(1 << n);
	for(int i = 0; i < (1<<n); ++i) 
		cin >> f[i];
	
	A1(n, f);
	A2(n, f);
	A3(n, f);
}

signed main()
{
    solve();
}

/*

Input : 
3
1 2 3 4 5 6 7 8 

Output :
1 3 4 10 6 14 16 36 
1 3 4 10 6 14 16 36 
1 3 4 10 6 14 16 36 

*/
