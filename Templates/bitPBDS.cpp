//PBDS using BIT

#include <bits/stdc++.h> 
using namespace std; 
#define VI vector<int> 
const int mxN = 2*1e5 + 5; 
int n , q;
vector<int> BIT(mxN); 

void update(int i, int add) 
{ 
	while (i > 0 && i < BIT.size()) 
	{ 
		BIT[i] += add; 
		i = i + (i & (-i)); 
	} 
} 
int sum(int i) 
{ 
	int ans = 0; 
	while (i > 0) 
	{ 
		ans += BIT[i]; 
		i = i - (i & (-i)); 
	} 
	return ans; 
} 

// Returns lower bound for k in BIT. 
int find_by_order(int k) 
{ 
	// Do binary search in BIT[] for given 
	// value k. 
	int l = 0; 
	int h = BIT.size(); 
	while (l < h) 
	{ 
		int mid = (l + h) / 2; 
		if (k <= sum(mid, BIT)) 
			h = mid; 
		else
			l = mid+1; 
	} 
	return l; 
} 

// Insert x into BIT. We basically increment 
// rank of all elements greater than x. 
void insert(int x) 
{ 
	update(x, 1, BIT); 
} 

// Delete x from BIT. We basically decreases 
// rank of all elements greater than x. 
void delete(int x) 
{ 
	update(x, -1, BIT); 
} 

// Returns rank of element. We basically 
// return sum of elements from start to 
// index x. 
int order_of_key(int x) 
{ 
	return sum(x, BIT); 
} 

// Driver code 
int main() 
{ 
	cin >> n >> q;
	VI a(n);
	for(int i =0 ; i < n;++i) {
		cin >> a[i];
		insert(a[i]);
	}
	while(q-- ){
		int qt;
		int l , r;
		cin >> qt >> l >> r;
		if(qt == 1) {
			
		} else {
			
		}
	}
	cout << "2nd Smallest element is "
	<< find_by_order(2, BIT) << endl; 

	cout << "Rank of 40 is "
		<< order_of_key(40, BIT) << endl; 

	delete(40, BIT); 

	cout << "Rank of 50 is "
		<< order_of_key(50, BIT) << endl; 

	return 0; 
} 
