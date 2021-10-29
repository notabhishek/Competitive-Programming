#include <stdio.h>
#define ll int
#define gc getchar_unlocked
#define max(a,b) (a)<(b)?(b):(a)
                        
signed main()
{                   
    const register ll INF = 5e8 + 1000;
    register int n = 0, K = 0, d = 0, m = 0, c, val, i, k;
   
    for (c = gc(); c != 32; c = gc())
        n = (n << 1) + (n << 3) + c - 48;

    for (c = gc(); c != 32; c = gc())
        K = (K << 1) + (K << 3) + c - 48; 
                         
    for (c = gc(); c != 32; c = gc())
        d = (d << 1) + (d << 3) + c - 48;

    for (c = gc(); c != 10; c = gc())
        m = (m << 1) + (m << 3) + c - 48;
    ++d; // increase d

    register ll ins, er;
    int a[n + 1];
    ll dp0[n + 1];
    ll dp1[n + 1];
    ll pref[n + 1];
    pref[0] = dp1[0] = 0;
    for (i = 1; i <= n; ++i)
    {
        for (val = 0, c = gc(); c > 47 && c < 58; c = gc())
            val = (val << 1) + (val << 3) + c - 48;
        a[i] = val;
        pref[i] = pref[i - 1] + m * val;
        dp1[i] = dp1[i - 1] + val;
    }

    register int bit = 1;
    int index[n + 1];
	ll value[n + 1];
	register int front = 0, back = 0;
	
    for (k = 1; k <= K; ++k)
    {
        front = back = 0;
        index[0] = 0;
        value[0] = -INF;

        if (bit == 0)
        {
            dp1[0] = -INF;
            // fill dp1 using dp0
            for (i = 1; i <= n; ++i)
            {
                if (index[front] <= i - d)
                {
                    ++front;
                }
                dp1[i] = a[i] + dp1[i - 1];
                // today we buy
                dp1[i] = max(dp1[i], dp0[i - 1]);
                dp1[i] = max(dp1[i], pref[i] + value[front]);
                ins = dp0[i - 1] - pref[i];

                // insert in maxDeque
                while (back >= front && value[back] <= ins)
                {
                    --back;
                }
                ++back;
                value[back] = ins;
                index[back] = i;
            }
            bit = 1;
        }
        else
        {
            dp0[0] = -INF;
            // fill dp0 using dp1
            for (i = 1; i <= n; ++i)
            {
                // today we get normal returns
                if (index[front] <= i - d)
                {
                    ++front;
                }

                dp0[i] = a[i] + dp0[i - 1];
                // today we buy
                dp0[i] = max(dp0[i], dp1[i - 1]);
                dp0[i] = max(dp0[i], pref[i] + value[front]);
                ins = dp1[i - 1] - pref[i];

                // insert in maxDeque
                while (back >= front && value[back] <= ins)
                {
                    --back;
                }
                ++back;
                value[back] = ins;
                index[back] = i;
            }
            bit = 0;
        }
    }
    if (bit == 1)
        printf("%d", dp1[n]);
    else
        printf("%d", dp0[n]);
}
