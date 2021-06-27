#include<bits/stdc++.h>
using namespace std;

struct BIT2D {
	vector<vector<int>> BIT2D;
	int max_x , max_y;
	
	void upd(int x, int y, int val) {
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
	
	void build(int maxx,int maxy,vector<vector<int>> &a){
	  max_x = maxx;
	  max_y = maxy;
	  BIT2D.resize(max_x + 1, vector<int> (max_y + 1 , 0) );
	  for(int i = 0 ; i < maxx; ++i){
	      for(int j =0; j< maxy;++j){
	          upd(i+1 , j+1 , a[i][j]);
	      }
	  }
	}
	
	int query(int x, int y){
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
	  return ans;
	}
	
	int query(int tR, int tC, int bR, int bC) {
		--tR; --tC;
		return query(bR,bC) - query(bR,tC) - query(tR,bC) + query(tR,tC);
	}
};

int main(){
	vector<vector<int>> a(5, vector<int>(6, 1));
	BIT2D bit;
	bit.build(5, 6, a);
	
	for(int i = 0; i <= 5; ++i) {
		for(int j = 0; j <=6; ++j) cout<< bit.query(i,j) << " ";
		cout << "\n";
	}
	cout << bit.query(1,1,5,5) << endl;
	cout << bit.query(1,3,4,5) << endl;
	cout << bit.query(2,3,5,6) << endl;
return 0;
}
