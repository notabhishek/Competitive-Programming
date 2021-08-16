# MathWorks 

- HackerRank test 
- 90 minutes

## Problems 
- Everyone had different problems, 2 coding problems + 44 mcqs(single + multicorrect) in 90 minutes, Python mcqs were present as Bonus section. Both coding problems had to be solved in different languages from C, C++, Java

Below are some of the coding problems

### 1. Simple Queries
- Given 2 arrays A, B (|A| , |B| <= 1e5), for each B[i], find number of elements in A such that A[j] <= B[i]
```
Sample Input:
4
1 4 2 4
2 
3 5
Sample Output:
2 4
```
##### Logic: 
- Sort A and binary search for each B[i]
```cpp
vector<int> counts(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	vector<int> ans;
	for(int i = 0; i < b.size(); ++i) {
		int it = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
		ans.push_back(it);
	}
	return ans;
}
```
### 2. Maximum Difference in Array 
- Given an array A (|A| <= 1e5 ), find max value of A[i] - A[j] where j <= i
```
Sample Input:
6
7 9 5 6 3 2 
Sample Output:
2
```
##### Logic: 
- iterate and store minimum value in left side to get maximum difference 
```c
int max_difference(int *a, int n) {
	int ans = 0, mn = a[0];
	for(int i = 1; i < n; ++i) {
		if(ans < a[i] - mn) ans = a[i] - mn;
		if(a[i] < mn) mn = a[i];
	}
	return ans;
}
```

### 3. Distinct Pairs
- Given an array A (|A| <= 1e5) and a target, find number of distinct unordered pairs (A[i], A[j]) such that A[i] + A[j] = target
```
Sample Input:
8
1 2 3 6 7 8 9 1 
10
Sample Output:
3

Explanation: 
Distinct pairs: (1,9), (2,8), (3,7)
```
##### Logic: 
- Use Hashset to check if target-A[i] is present in A
```java
static int numberOfPairs(int[] b, long k) {
    int n = b.length;
    long[] a = new long[n];
    for(int i = 0; i < n; ++i) a[i] = b[i];
    HashMap<Long, Long> hash = new HashMap<>();
    for (int i = 0; i < n; i++) {
        if (!hash.containsKey(a[i]))
            hash.put(a[i], (long)0);
        hash.put(a[i], hash.get(a[i]) + 1);
    }
    int pairs = 0;
    TreeSet<Long> st = new TreeSet<>();
    for (int i = 0; i < n; i++) {
        if (hash.get(k - a[i]) != null) {
          if(k-a[i] == a[i]) {
            if(hash.get(a[i]) > 1) st.add(a[i] * 1000000000L + a[i]);
          } else {
            long u = Math.min(a[i], k-a[i]);
            long v = Math.max(a[i], k-a[i]);
            st.add(u * 1000000000L + v);
          }
        }
    }
    return st.size();
}
```

### 4. Diamond Mine
- Same as [LeetCode Cherry Pickup](https://leetcode.com/problems/cherry-pickup/)
##### Logic:
- Dynamic Programming
- Optimization: to reduce dp state from dp(r1,c1,r2,c2) we can observe that c2 = r1+c1-r2, thus we can only store 3 values dp(r1,c1,r2)
```cpp
const int INF = 1e7;
vector<vector< vector<int>>> dp;
vector<vector< vector<bool>>> f;
int rec(int r1, int c1, int r2, vector<vector<int>>&a) {
    int c2 = r1 + c1 - r2;
    if(r1 >= a.size() || c1 >= a.size() || r2>=a.size() || c2>=a.size() )
        return -INF;
    if(a[r1][c1] == -1 || a[r2][c2] == -1)
        return -INF;
    int &ret = dp[r1][c1][r2];
    if(f[r1][c1][r2]) 
        return ret;

    int cur = 0;
    if(a[r1][c1] == 1) ++cur;
    if(a[r2][c2] == 1) ++cur;
    if(r1 == r2 && c1 == c2 && a[r1][c1] == 1) --cur;  //same cherry counted twice


    ret = max(ret , cur + rec(r1 + 1 , c1 , r2, a));
    ret = max(ret , cur + rec(r1 + 1 , c1 , r2+1, a));
    ret = max(ret , cur + rec(r1, c1+1 , r2, a));
    ret = max(ret , cur + rec(r1, c1+1 , r2+1, a));

    f[r1][c1][r2] = 1;
    return ret;
}
int cherryPickup(vector<vector<int>>& a) {
    int n = a.size();    
    dp.resize(n , vector<vector<int>> (n , vector<int> (n, -INF)));
    f.resize(n , vector<vector<bool>> (n , vector<bool> (n, 0)));
    dp[n-1][n-1][n-1] = a[n-1][n-1];
    f[n-1][n-1][n-1] = 1;
    int ans = rec(0, 0, 0, a);
    ans = max(ans, 0);
    return ans;
}
```

### 5. Beautiful Arrangements 
- Given an integer N ( 1<= N <= 20), find the number of permutations of 1-N such that for every 1<=i<=N, A[i]%i = 0 or i%A[i] = 0
```
Sample Input1:
2
Sample Output1:
2

Sample Input2:
3
Sample Output2:
3
```
##### Logic:
- Bitmask + dp
```cpp
vector<vector<int>> dp;
int rec(int i, int mask, int n) {
	if(i == 0) return 1;
	int &ret = dp[i][mask];
	if(ret != -1) return ret;
	ret = 0;
	for(int j = 0; j < n; ++j) {
		bool div = (i%(j+1) == 0) || ((j+1)%i == 0);
		if(div && ((1<<j) & mask) == 0) {
			ret += rec(i-1, mask ^ (1<<j), n);
		} 
	}
	return ret;
}
void solve()
{
	int n;
	cin >> n;
	dp.resize(n+1, vector<int>(1<<n, -1));
	cout << rec(n, 0, n) << "\n";
}
```
