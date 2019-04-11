#include<stdio.h>
#include<stdlib.h>
int equal1(int* arr, int n)
{
    int i;
    for(i=1;i<n;i++)
        if(arr[i]!=arr[i-1]) return 0;
    return 1;
}
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int i,t,max,j,w[10001],n,steps,key;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        steps = 0;
        qsort(w,n,sizeof(int),cmp);
        while(!equal1(w,n))
        {
            for(i=1;i<n;i++)
            {
                key = w[i];
                j = i - 1;
                while(j>=0 & w[j]>key)
                {
                    w[j+1] = w[j];
                    j--;
                }
                w[j+1]=key;
            }
            max = w[n-1];
            i = n - 1;
            while( w[i]==max & i>=0 )
            {
                w[i]--;
                i--;
                steps++;
            }
        }
        printf("%d\n",steps); 
    }
    return 0;
}