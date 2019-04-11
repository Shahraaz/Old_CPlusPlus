#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,init,endin,n,i,q;
    bool coin[100000]={false};
    cin >> n >> q;
    while(q--)
    {
        cin >> a >> init >> endin ;
        if(a==0)
        {
            for(i=init;i<=endin;i++)
                if(coin[i])
                    coin[i] = false;
                else 
                    coin[i] = true;
        }
        else
        {
            a = 0;
            if(coin[endin]) a = 1;
            cout<<a+count(coin+init,coin+endin,true)<<endl;
        }
    }
    return 0;
}