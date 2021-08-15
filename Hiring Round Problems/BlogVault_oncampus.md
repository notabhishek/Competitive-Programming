# BlogVault
### 1. Sort if you can
- Given an array A ( |A| <= 1e5), you can perform the following operation
- Move the first element X places to the right, 0<=X<N, cost = X ( distance moved)
- Find the minimum cost to sort the array
```
Sample Input 1:
3
1 2 3
Sample Output 1:
0

Sample Input 2:
3
1 3 2
Sample Output 2:
3
```
Logic:
- 
```
```
### 2. Don't Sleep in lectures 
- Given an array A (|A|<=1e5), teacher teaches A[i] chapters in the ith minute
- and an array T, if T[i] = 1, you are awake at ith minute and you understand A[i] chapters
- You have a special power that allows you to stay awake for at max K minutes, i.e. you can make any subarray(length <=K) of T all 1s
- Find the maximum chapters you can understand
```
Sample Input:
3
6 1 3 5 2 5 4
6 1 1 0 1 0 0
Sample Output:
16
```
#### Logic: 
- Store prefix sum of A[i] and another prefix sum of chapters you understood till i
- Then iterate over i, and you can get ans in O(1) for setting 1 subarray of size K
```
int solve(int k, vector<int> &a, vector<int> &t)
{
	int n = a.size();
	vector<int> pa(n+1, 0); // prefix of a 
	vector<int> pt(n+1, 0); // prefix of chapters understood
	int ans= 0;
	for(int i = 1; i <= n; ++i) {
		pa[i] = pa[i-1] + a[i-1];
		pt[i] = pt[i-1];
		if(t[i-1] == 1) pt[i] += a[i-1];
	}
	ans = pt[n];
	for(int i = 0; i +k <= n; ++i) {
		int cur = pa[i+k]-pa[i] - (pt[i+k] - pt[i]);
		// max understood  = pt[n] + sum(i..i+k) - (chapters in i..i+k that you already understood)
		ans = max(ans, pt[n] + cur);
	}
	return ans ;
}
```
### 3. String Conversion
- Given a string R (|R| <= 1e5)
- Convert a string initially S, |S| = |R|, s[i] = '.' initially for all i, you can perform the following operation
- Choose substring i..j of S and a char C, then make s[k] = C for all i<=k<=j
- Find minimum number of operations to make R = S
```
Sample Input:
aabbca
Sample Output:
3
```
#### Logic:
- Dynamic Programming
```
int solve(string s)
{
    int n = s.size();
    int mem[n][n];
    memset(mem, 0, sizeof mem);
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
        {
        	if(i == j) mem[i][j] = 1;
        	else mem[i][j] = 1 + mem[i+1][j];
        	
            for (int k = i + 1; k <= j; k++) {
                if (s[k] == s[i]) {
                	int x = mem[i + 1][k - 1] + mem[k][j];
                    mem[i][j] = min(mem[i][j], x);
        		}
        	}
        }
    int ans = (n == 0 ? 0 : mem[0][n - 1]);
    return ans;
}
```
