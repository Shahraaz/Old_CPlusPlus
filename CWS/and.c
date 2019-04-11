#include<stdio.h>
int main()
{
    long int n,bitcount;
    scanf("%d",&n);
    int i,arr[n],j;
    long long int sum,temp;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0,sum=0;i<32;i++)
    {
        bitcount = 0;
        for(j=0,temp=1<<i;j<n;j++)
            if(temp&arr[j]) bitcount++;
        sum += bitcount*(bitcount-1)/2*temp;
    }
    printf("%lld\n",sum);
    return 0;
}