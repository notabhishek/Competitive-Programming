// Problem: Lockdown Loss
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/ECODOWN
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Solution: https://www.codechef.com/submit/complete/48912561

// Code by : Abhishek Tiwari @devil_within


// Non linear recurrence, converted to linear 
// use mod-1 since we are dealing with powers 

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000006   // -1 because we are working with powers
using ll = long long;
//Check line 168 for mul errors
template <typename T>
class Matrix {

public:

    vector < vector <T> > A;
    int r,c;
    Matrix()
    {
        this->r = 0;
        this->c = 0;
    }
    Matrix(int r,int c)
    {
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }
    Matrix(int r,int c,const T &val)
    {

        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }
    Matrix(int n)
    {
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }
    
    void resize(int r , int c) {
    	this->r = r;
    	this->c = c;
		A.resize(r);
		for(auto &i : this->A) 
			i.resize(c);
    }
    void resize(int r , int c , const T &val) {
    	this->r = r;
    	this->c = c;
		A.resize(r);
		for(auto &i : this->A) 
			i.resize(c , val);
    }
    
    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout << A[i][j] << " ";

            cout << endl;
        }
    }
    void input()
    {
        // for(int i=0;i<r;i++)
        //     for(int j=0;j<c;j++)
        //         define inout here
    }
    Matrix operator * (const Matrix<T> &B)
    {
        
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                {
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }

        return C;
    }
    void operator *= (const Matrix<T> &B)
    {
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                {
                    C[i][j] = (C[i][j] + ( (long long)A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }
        this->r = C.r;
        this->c = C.c;
        this->A = C.A;
    }
    Matrix operator + (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                #endif
            }

        return C;
    }
    void operator += (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                A[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                A[i][j] %= mod;
                #endif
            }
    }
    Matrix operator - ()
    {
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = -A[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }
    Matrix operator - (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }
    void operator -= (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                A[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                A[i][j] %= mod;
                if(A[i][j] < 0)
                    A[i][j] += mod;
                #endif
            }
    }
    Matrix operator ^ (long long n)
    {
        assert(r == c);

        int i,j;
        Matrix <T> C(r);

        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n)
        {
            if(n&1)
                C *= X;

            X *= X;
            n /= 2;
        }
        return C;
    }
    void operator ^= (long long n)
    {
        assert(r == c);

        int i,j;
        Matrix <T> C(r) ;

        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n)
        {
            if(n&1)
                C *= (*this);

            (*this) *= (*this);
            n /= 2;
        }
        this->A = C.A;
    }
    Matrix transpose()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        return C;
    }
    void transposeInplace()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        this->r = C.r;
        this->c = C.c;
        this->A = C.A;
    }
    vector<T>& operator [] (int i)
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }
    const vector<T>& operator [] (int i) const
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }
    friend ostream& operator << (ostream &out,const Matrix<T> &M)
    {
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }
    friend istream& operator >> (istream &in,Matrix<T> &M)
    {
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                in >> M[i][j];
            }
        }
        return in;
    }
    
};

/*
Fibonacci 
f0 = 0, f1 = 1,  f(n) = f(n-1) + f(n-2)

1 1		X 	f(n)	=	f(n)+f(n-1)
1 0		X 	f(n-1)	=	f(n)

=>

f(n)		= A^n-1 f[0]
f(n-1) 				f[1]
*/

ll fpow(ll b, ll e, ll modd) {
    ll ans=1; for(;e;b=b*b%modd,e/=2) if(e&1) ans=ans*b%modd; return ans; }

	
int main()
{
	int tc;
	cin >> tc;
	while(tc--) {
		ll p , q , n;
		cin >> p  >> q >> n;
		if(n == 0) {
			cout << p << "\n";
			continue;
		}
		/*
		Fn = Fn-1 + Fn-2 + Fn-1*Fn-2
		1+Fn = (1+Fn-1) * (1 + Fn-2)
		Gn = Gn-1 * Gn-2
		
		logGn = LogGn-1 + logGn-2
		Fibonacci but modullo  mod-1, since we are dealing with powers
		logG0 = log2(f0+1)
		logG1 = log2(f1+1)
		F(n) = (2^ logGn) - 1  
		*/
	    Matrix <ll> A(2,2);
	    A[0][0] = 1;
	    A[0][1] = 1;
	    A[1][0] = 1;
	    A[1][1] = 0;
	    
	    A = A^(n-1);
	    
		// cout << A;
		/*
		2^( a00log2(q+1) + a01log2(p+1)) 
		= 2^(a00log2(q+1)) * 2^(a01log2(p+1))
		= (2^log2(q+1)) ^ a00   * ( ... )
		= (q+1) ^ a00  * (p+1) ^ a01
		*/
		ll ans = (fpow(q+1, A[0][0], mod+1) * fpow(p+1, A[0][1], mod+1) );
		ans %= (mod + 1); // mod is 1e9 + 7  -1
		ans = (ans - 1 + mod + 1) % (mod+1);
		cout << ans << "\n"; 
	}
}
