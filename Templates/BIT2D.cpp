#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> BIT2D;
int max_x , max_y;

void update(int x, int y, int val) {
  int y1;
  while (x <= max_x) {
    y1 = y;
    while (y1 <= max_y) {
      BIT2D[x][y1] += val;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}
void read(int x, int y){
  int ans =0;
  int y1;
  while (x > 0) {
    y1 = y;
    while (y1 >0) {
      ans += BIT2D[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
}
void build(int maxx,int maxy,vector<vector<int>> a){
  max_x = maxx;
  max_y = maxy;
  BIT2D.resize(max_x + 1, vector<int> (max_y + 1 , 0) );
  for(int i = 0 ; i < maxx; ++i){
      for(int j =0; j< maxy;++j){
          update(i+1 , j+1 , a[i][j]);
      }
  }
}
int main(){


return 0;
}