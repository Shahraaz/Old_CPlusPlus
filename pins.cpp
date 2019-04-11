#include <stdio.h>
#include <iostream>
using namespace std;

void printer(int n)
{
    long int fact=10000000000000;//362880;
    printf("%d",fact);
}
int main()
{
    int t,n,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1) printf("1 1\n");
        else
        {
            printf("1 ");
            printer(n);
            printf("\n");
        }
    }
    return 0;
}