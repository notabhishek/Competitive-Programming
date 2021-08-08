#include <bits/stdc++.h>
using namespace std;


// longest proper prefix which is also suffix
vector<int> prefixFunction(string &s) {
	int n = s.length();
	vector<int> prefix(n, 0);
	for(int i = 1; i < n; ++i) {
		int j = prefix[i-1];
		
		while(j > 0 && s[i] != s[j]) {
			j = prefix[j-1];
		}
		
		prefix[i] = j + (s[i]==s[j]);
	}
	return prefix;
}

// change j to get positions >= j
void KMP(string &pat, string &txt, int j = 0) {
	vector<int> match; //matching positions
	vector<int> prefix = prefixFunction(pat);
	int i = 0;
	while(j  < txt.size()) {
		if(txt[j] == pat[i]) { 
			j++;
			i++;
		} else {
			// doesn'txt match, use prefix array
			if(i > 0)
				i = prefix[i-1];
			else 
				j++;
		}
		if(i == pat.size()) {
			match.push_back(j - pat.size());
			i = 0;
		} 
	}
	
	for(auto &j : match) cout << j << " "; cout << "\n";
}

void solve()
{
	string s, t;
	cin >> s >> t;
	// find all occurences
	KMP(s, t);
	// find occurences at text-idx >= 3
	KMP(s, t, 3);
}

signed main()
{
    // freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        // cout << "Case #"<<tc<<": \n";
        solve();
    }
}

/*
Input:
ab
abcabcdabcde

Output:
0 3 7 
3 7 
*/
