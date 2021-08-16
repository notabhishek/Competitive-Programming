# CashFree


## Offer

```
CashFree Campus Hiring 6-months+FTE

Eligibility Criteria
Course - B. Tech
Branch - CSE, ECE
Graduation Year- 2022
CGPA- 7 and above

Job Designation - Software Development Engineer

Tentative Date of Joining - June, 2022
Place of Posting - Bangalore / WFH
Bond - None
Internship Stipend(for 6 months) - Rs. 35,000 pm
CTC -  16,00,000 
{ 14,00,000 base + 1 lakh(retention, payable after 1 year) +
  1 lakh(perks)}
```

## Total Time - 90 mins

## Problems

## 1. Alice and Her Gadget
 Given a string of digits of size N. Alice's gadget can display one digit a time on a seven segment display. Find minimum number of toggle required to display all digits if initially all bulbs of display were off.

#### Input Format:
- T - Number of test cases (1 <= T <= 1000)
  - N - Length of string ( 1 <= N <= 1e6 )
  - s - string

```
Sample Input: 
2
2
13
3
123

Sample Output:
5
9
```
#### Logic : Bruteforce
- Keep track of previous digit and toggle bulbs accodring to current digit.

```cpp
int solve(int N, string s){
   int minToggle = 0;

   map<int, vector<int>> m;

   m[0] = { 1, 1, 1, 1, 1, 1, 0 };
   m[1] = { 0, 1, 1, 0, 0, 0, 0 };
   m[2] = { 1, 1, 0, 1, 1, 0, 1 };
   m[3] = { 1, 1, 1, 1, 0, 0, 1 };
   m[4] = { 0, 1, 1, 0, 0, 1, 1 };
   m[5] = { 1, 0, 1, 1, 0, 1, 1 };
   m[6] = { 0, 0, 1, 1, 1, 1, 1 };
   m[7] = { 1, 1, 1, 0, 0, 0, 0 };
   m[8] = { 1, 1, 1, 1, 1, 1, 1 };
   m[9] = { 1, 1, 1, 0, 0, 1, 1 };

   vector<int> switches(7, 0);
   
   for(int i = 0; i < N; i++){
       int digit = s[i] - '0';
       for(int j = 0; j < 7; j++){
           if(switches[j] != m[digit][j]){
              minToggle++;
           }
       }
       switches = m[digit];
   }
   return minToggle;
}
```
## 2. Calculate Cost
Given N toys & their prices and you can remeber at most K distinct prices. If you don't remember price, you have to pay $X. Find cost you need to pay.

#### Input Format :
- T - Number of test cases (1 <= T <= 10)
  - N - Number of toys ( 1 <= N <= 1e5 )
  - K - Number of distinct prices you can remember ( 1 <= K <= N )
  - X - Price you have to pay (1 <= X <= 1e9)
  - Array of prices (1 <= price[i] <= 1e9)

```
Sample Input: 
1
4 2 5
1 2 3 1

Sample Output:
5
```
#### Logic : Greedy
- Find number of distinct prices. If they are greater than K, pay X for each extra toy.

```cpp
int solve(int N, int K, int X, vector<int> &prices){
   set<int> s(prices.begin(), prices.end());
   return max( int(0), s.size() - K ) * X;
}
```
## 3. Water and the grid
Given a 2d grid of character in the form of M * N where '*' represents a tower of height 1 unit and '.' represents empty cell. Estimate volume of water than could be trapped in between towers.

#### Input Format :
- M, N : height, width of grid ( 1 <= M * N <= 1e6 )
- Grid of characters
```
Sample Input: 
4 4
.**.
*.*.
*..*
****

Sample Output:
3
```
#### Logic : DFS
- Find all empty cells that can leak by DFS and the remaining empty cell will hold water.

```cpp
int dr = { 0, 0, 1, -1 };
int dc = { 1, -1, 0, 0 };

void dfs(int M, int N, vector<vector<char>> &grid, int r, int c){
   grid[r][c] = '*';
   
   for(int i = 0; i < 4; i++){
       int rr = r + dr[i], cc = c + dc[i];
       if(rr >= 0 && rr < M && cc >= 0 && cc < N && grid[rr][cc] == '.'){
          dfs(M, N, grid, rr, cc);
       }
   }
}

int solve(int M, int N, vector<vector<char>> grid){
   for(int r = 0; r < M; r++){
       for(int c = 0; c < N; c++){
           if((r == 0 || c == 0) && grid[r][c] == '.'){
              dfs(M, N, grid, r, c);
           }
       }
   }

   int trappedWater = 0;

   for(int r = 0; r < M; r++){
       for(int c = 0; c < N; c++){
           if(grid[r][c] == '.') trappedWater++;
       }
   }
   return trappedWater;
}
```
## 3. Disappearance of intergars 
Initially at t = 0 there a array of integers of size N. Each second a integer disappears for N seconds and after N seconds it reappears at is original location. First all odd index element disappear from left to right then even index elements disappear from left to right. We have Q queries consisting of t and m, find m<sup>th</sup> interger from left at t<sup>th</sup> sec ( print -1 if there is no integer at m<sup>th</sup> position ).

#### Input Format :
- N : Size of array ( 1 <= N <= 1e6 )
- array of integers ( 0 <= A[i] <= 1e9 )
- Q : Number of queries ( 1 <= Q <= 1e6 )
  - t : time ( 0 <= t <=  1e18)
  - m : element position from left ( 1 <= m <= 1e6 )
```
Sample Input: 
5
1 2 3 4 5
5
1 4
2 1
9 4
4 2
21 1

Sample Output:
5
2
5
-1
2
```
#### Logic : Binary search
- Do binary search to find number of elements on left of current index.
- If number of elements on left is m previous index will be answer.

```cpp

int cnt(int t, int m, int N){
   int ans = m;

   ans -= min((m+1)/2, t); // Disappearing odd index element
   if(t >= (N+1)/2){
      ans -= min(m/2, t - (n+1)/2); // Disappearing even index element
      if(t >= N){
         ans += min((m+1)/2, t-n); // Reappearing odd index element
         if(t - n >= (n+1)/2){
            ans += min(m/2, t-n-(n+1)/2); // Reappearing even index element
         }
      }
   }
   return ans;
}

// call solve for each query
int solve(int N, vector<int> &A, int t, int m){
   t %= 2 * N;
   int L = 1, R = N;
   while(L <= R){
      int mid = ( L + R ) / 2;
      if(cnt(t, mid, N) >= m){
         R = mid - 1;
      }else{
         L = mid + 1;
      }
   }
   
   if(R >= 0 && R < N){
      return A[R];
   }
   return -1;
}
```



