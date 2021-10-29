#include <stdio.h>
#define gc getchar_unlocked
int main()
{

    register int n = 0, c= gc();
    for (; c > 32; c = gc())
    {
        n = (n << 1) + (n << 3) + c - 48;
    }
    register int i, lmax = 0, r = n - 1, x = 0;


    int values[n];

    for (i = 0; i < n; ++i)
    {

        c = gc();
        x = 0;
        for (; c > 32; c = gc())
        {
            x = (x << 1) + (x << 3) + c - 48;
        } 
		x = x<< 1;
        if (x > lmax) 
            values[i] = lmax = x;
        else
            values[i] = (x|1);
    }
    lmax = 0;

    for (; i--;)
    {

        x = values[i];

        if ((x & 1) == 1)
        {
			x^= 1;
            if (x > lmax)
                lmax = x;
            else
                ++r;

        }
        else if (x > lmax)
            lmax = x;
    }

    printf("%d", r);

    return 0;

}
