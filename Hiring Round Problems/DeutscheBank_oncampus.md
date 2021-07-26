# Deutsche Bank

### 1. Increasing sequence 
- Given an array having N elements (N < 1e5), for every index i, you do a[i] = a[i] - X where  0<=X<=a[i]
- Print YES if the array can be made strictly increasing, else NO
```
void solve()
{
	int n;
	cin >> n;
	bool f = 1;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		if(x < i) f = 0;
	}
	if(f) cout << "YES\n";
	else cout << "NO\n";
}
```

### 2. The abandoned city
- Given an array A ( size N < 1e5 , 0 < A[i] < 1e9) and an integer K
- Calculate length of smallest subarray s.t. sum(subarray)  >= K
```
// 2 pointer 
int solve(int n, vector<int> c, int x)
{
	--x;
	int cs = 0, ans = n + 1;
    int i = 0, j = 0;
    while (j < n) {
        while (cs <= x && j < n)
            cs += c[j++];
 
        while (cs > x && i < n) {
                ans = min(ans, j - i);
            cs -= c[i++];
        }
    }
    return ans;
}
```

### 3. Minimum Susbtring
Given a string S (size < 1e5), find length of smallest substring which has T = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" as subsequence.
```
\\ dp N * 26
signed main()
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = n + 1;
    vector< vector<int>> pos(n+1, vector<int> (26, -1));
    for(int i = n-1; i >= 0; --i) {
      pos[i] = pos[i+1];
      pos[i][s[i] - 'A'] = i;
    }
    for(int i = 0; i < n; ++i) {
      char next = 'A';
      int u = i;
      while(u != -1 && next <='Z') {
        u = pos[u][next-'A'];
        ++next;
      }
      if(next > 'Z') {
        ans  = min(ans, u - i + 1);
      }
    }
    cout << ans << "\n";
}
```
