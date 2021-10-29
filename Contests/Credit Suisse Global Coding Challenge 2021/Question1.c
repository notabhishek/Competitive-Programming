#include<stdio.h>   
#define gc getchar_unlocked 
int main(void) {    
    register int x = 0, c = gc();
    while(c != -1) {
        x = (x << 1) + (x << 3) + c - 48;
        c = gc(); 
    } 
    printf("%d",((x << 1)+ 1)/3);    
    return 0;  
}     
