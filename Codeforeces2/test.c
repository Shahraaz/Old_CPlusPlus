#include <stdio.h>

int main() {
    int i,t,fact,d ;
    scanf ("%d",&t);
    int n[t],m[t] ;
    while(t--)
    {
        scanf(" %d %d",&n[t],&m[t]);
        for(i=0,fact=1,d=(n[t]>m[t]?m[t]:n[t]);i<d;i++)
            fact *= (m[t]+n[t]-i)/(d-i);
        printf("%d\n",fact);
    }
}
