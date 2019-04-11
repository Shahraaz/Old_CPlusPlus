#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,m,n,i,temp;
    cin >> t;
    while(t--)
    {
        cin >>  m >> n;
        if(m==1) m++;
        n++;
        for(;m<n;m++)
        {
            temp = sqrt(m);
            temp++;
            for(i=2;i<temp;i++)
                if(m%i==0) goto endin;
            cout << m << endl;
            endin : ;
        }
    }
    return 0;
}