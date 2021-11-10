// numbers < R with given digitsum
#include<bits/stdc++.h>
using namespace std;

int dp[101][181][2]; // dp[length][dsum][tight]

int solve(string &num, int n, int x, bool tight) {
	// base case
	if(n == 0) 
		return x == 0;
	if(dp[n][x][tight] != -1) 
		return dp[n][x][tight];
	
	int ub = tight ? num[num.length()-n]-'0' : 9;
	int answer = 0;
	for(int dig = 0; dig <= ub; ++dig) {
		answer += solve(num, n-1, x-dig, tight & (dig == ub));
	}
	
	return dp[n][x][tight] = answer;
}

int main() {
	
	string num;
	int dsum;
	cin >> num >> dsum;
	memset(dp, -1, sizeof dp);
	cout << solve(num, num.length(), dsum, 1);
	return 0;
}
