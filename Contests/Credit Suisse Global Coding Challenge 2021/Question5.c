#include <stdio.h> 
#define pc putchar_unlocked
#define gc getchar_unlocked
void main() 
{
    register int c = gc(), mx = 0, mx2 = 0, i = 0, d;
    for (; c > 0; c = gc())
    {
        if (c == 49)
        {
            if (i >= mx)
            {
                mx2 = mx;
                mx = i;
            }   
            else if (i > mx2)
                mx2 = i;
            i = 0;
        }
        else
            ++i;
    }
    if (i >= mx)
    {
        mx2 = mx;
        mx = i;
    }
    else if (i > mx2)
        mx2 = i;
    d = (mx + 1) >> 1;
    if (mx2 > (mx>>1))
    {
    	if(d > mx2) {
    	    pc('A');
    	    return;
    	}
    	else { 
    	    pc('B');
    	    return;
        }
    }
    else
    {
    	if((d<<1) > mx) {
    	       pc('A');
    	       return;
    	}
    	else {
    	    pc('B');
    	    return;
    	}
    }
}
