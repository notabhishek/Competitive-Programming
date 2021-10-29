#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

#define NX 1000002 
#define MOD 1000000007

#define ll long long
#define gc getchar

bool pr[NX];

// for DSU
int par[NX];
int getp(register int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getp(par[u]);
}

int main()
{
    // srand(time(0));
    register int n = 0, val, c, u, v, i, j, tcs = 0;
    c = gc();

    for (; c != 10; c = gc())
    {
        n = (n << 1) + (n << 3) + c - 48;
    }
    for (i = 0; i < n; ++i)
    {
        // reading value[i]
        c = gc();
        val = 0;
        for (; c <= 47 || c >= 58; c = gc())
        ;
        for (; c > 47 && c < 58; c = gc())
        {
            val = (val << 1) + (val << 3) + c - 48;
        }
        // initialize DSU
        if (val == 1)
        {
            ++tcs;
        }
        else if (par[val] == 0)
        {
            ++tcs;
            par[val] = val;
        }
    }

    
	
    for (i = 2; i < NX; ++i)
    {
        if (pr[i] == 0)
        {
            u = 0;
            for (j = i; j < NX; j = j + i)
            {
                pr[j] = 1;
                if (par[j] > 0)
                {
                    if (u == 0)
                        u = getp(j);
                    else
                    {
                        v = j;
                        // u = getp(u);
                        // while (par[u] != u)
                        // {
                        //     par[u] = par[par[u]];
                        //     u = par[u];
                        // }

                        v = getp(v);
                        // while (par[v] != v)
                        // {
                        //     par[v] = par[par[v]];
                        //     v = par[v];
                        // }

                        if (u == v)
                            continue;
                        // link directly
                         // par[v] = u;   
                            
                        // randomized linking
                        if ((rand() & 1) == 1)
                        {
                            par[u] = v;
                            u = v;
                        }
                        else
                        {
                            par[v] = u;
                        }
                        // if (siz[u] < siz[v])
                        // {
                        // (u ^= v), (v ^= u), (u ^= v); // swap u, v
                        // }
                        // siz[u] = siz[v] + siz[u];
                        // par[v] = u;
                        --tcs;
                    }
                }
            }
        }
    }

    // Calculate ans = 2 ^ totalComponents - 2

    register ll ans = 1, b = 2;
    for (; tcs; tcs >>= 1)
    {
        if (tcs & 1)
        {
            ans = ans * b;
            if (ans > MOD)
                ans = ans % MOD;
        }
        b = b * b;
        if (b > MOD)
            b = b % MOD;
    }
    ans = ans - 2;
    if (ans < 0)
        ans = ans + MOD;
    if (ans == 0)
        printf("NO\n0");
    else
        printf("YES\n%d", ans);

    return 0;
}
