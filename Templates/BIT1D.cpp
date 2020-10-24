//BIT Implementation 
//1 based indexing in BIT

#include<bits/stdc++.h>
using namespace std;
int64_t setBitNumber(int64_t n) { 
	for(int i = 0; i < 6; ++i){
    n |= n >> ( 1 << i );
  } 
  return ( (n+1) >> 1); 
} 

vector<int> BIT;
int MaxIdx;
void updateBIT(int idx, int val) {
  while (idx <= MaxIdx) {
    BIT[idx] += val;
    idx += (idx & -idx);
  }
}

int readBIT(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += BIT[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void buildBIT(int n , vector<int> &a){
    BIT.resize(n+1 , 0);
    MaxIdx = n;
    for(int i = 0; i < n ;++i)
        updateBIT( i+1 , a[i]);
}


int readSingle(int idx);
void scale(int c);
int find(int cumFre);
int findG(int cumFre);

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i :a ) cin>>i;
    buildBIT(n , a);
    //sum [0 to 5]
    cout<<"a[0] + a[1] + ..+a[5] = "<< readBIT(5 + 1) <<endl;
    cout<<"a[3] = "<<readSingle(3 + 1)<<endl;
    cout<<"a[3] = "<<readBIT(3 + 1 ) - readBIT(3)<<endl;
    a[3]+=6;
    //Update index 3
    updateBIT(3 + 1 , 6);
    //sum [0 to 5]
    cout<<"a[0] + a[1] + ..+a[5] = "<< readBIT(5 + 1) << endl;
    cout<<"a[3] = "<<readSingle(4)<<endl;
    cout<<"a[3] = "<<readBIT(4) - readBIT(3)<<endl;
return 0;
}

int readSingle(int idx) {
  int sum = BIT[idx]; // this sum will be decreased
  if (idx > 0) { // the special case
    int z = idx - (idx & -idx);
    idx--; // idx is not important anymore, so instead y, you can use idx
    while (idx != z) { // at some iteration idx (y) will become z
      sum -= BIT[idx];
      // substruct BIT frequency which is between y and "the same path"
      idx -= (idx & -idx);
    }
  }
  return sum;
}

void scale(int c) {
  for (int i = 1; i <= MaxIdx; i++)
    BIT[i] = BIT[i] / c;
}

// If in the BIT exists more than one index with the same
// cumulative frequency, this procedure will return 
// some of them

// bitMask - initialy, it is the greatest bit of MaxIdx
// bitMask stores the current interval that should be searched
int find(int cumFre) {
  int idx = 0; // this variable will be the output
  int bitMask = setBitNumber ( MaxIdx );
  while (bitMask != 0) {
    int tIdx = idx + bitMask; // the midpoint of the current interval
    bitMask >>= 1; // halve the current interval
    if (tIdx > MaxIdx) // avoid overflow
      continue;
    if (cumFre == BIT[tIdx]) // if it is equal, simply return tIdx
      return tIdx;
    else if (cumFre > BIT[tIdx]) {
      // if the BIT frequency "can fit" into cumFre,
      // then include it
      idx = tIdx; // update index
      cumFre -= BIT[tIdx]; // update the frequency for the next iteration
    }
  }
  if (cumFre != 0) // maybe the given cumulative frequency doesn't exist
    return -1;
  else
    return idx;
}

// If in the BIT exists more than one index with a same
// cumulative frequency, this procedure will return 
// the greatest one
int findG(int cumFre) {
  int idx = 0;
  int bitMask = setBitNumber ( MaxIdx );
  while (bitMask != 0) {
    int tIdx = idx + bitMask;
    bitMask >>= 1;
    if (tIdx > MaxIdx)
      continue;
    if (cumFre >= BIT[tIdx]) {
      // if the current cumulative frequency is equal to cumFre,
      // we are still looking for a higher index (if exists)
      idx = tIdx;
      cumFre -= BIT[tIdx];
    }
  }
  if (cumFre != 0)
    return -1;
  else
    return idx;
}