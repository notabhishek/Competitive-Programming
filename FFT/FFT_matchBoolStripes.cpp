// FFT template match two stripes
// given two boolean stripes, match them by rotating so that no two 1s are together

#include<bits/stdc++.h>
using namespace std;

#define int int64_t
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void printPoly(vector<int> &a) {
	for(int i = a.size()-1; i>0; --i) {
		if(a[i] != 0) cout << a[i] <<"*x^" << i << " + "; 
	}
	cout << a[0] << "\n";
}

signed main() {
	int n;
	cin >> n;
	
	vector< int > v1(n) , v2(n);
	for(auto &i: v1 ) cin >> i;
	for(auto &i: v2 ) cin >> i;
	
	vector< int > p1 = v1 , p2 = v2;
	reverse(p1.begin() , p1.end());
	for(int i = 0 ; i < n; ++i ) p1.push_back(0);
	for(int i = 0 ; i < n; ++i ) p2.push_back(p2[i]);

	vector<int> p1p2 = multiply(p1 , p2);
	for(int i = n-1; i < 2 * n - 1; ++i) {
		// cout << "lshift b by " << i - (n-1) << ", ans = " << p1p2[i] << "\n";
		if(p1p2[i] == 0) {
			cout << "lshift b by " << i - (n-1) << " is a match\n";
		}
	}
	
}

/*
Example : 
4
0 0 1 1 
0 1 1 0

answers : 
[0011][0110] = 1
[0011][1100] = 0
[0011][1001] = 1
[0011][0011] = 2

Output : 

lshift b by 1 is a match

*/