#include<stdio.h>
#include<math.h>
int main()
{
    int t,m,n,i,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        if(m==1) m++;
        n++;
        while(m<n)
        {
            temp = sqrt(m);
            temp++;
            for(i=2;i<temp;i++)
                if(m%i==0) goto endin;
            printf("%d\n",m);
            endin : m++;
        }
    }
    return 0;
}