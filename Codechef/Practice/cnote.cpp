#include<iostream>
using namespace std;
int main()
{
    int flag,t,y,x,k,c,n,p;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> k >> n;
        flag = 0;
        while(n--)
        {
            cin >> c >> p;
            if((c >= x-y)&p<=k)
                flag = 1;
        }
        if(flag==1) cout << "LuckyChef" << endl;
        else
        {
            if(x<=y) cout << "LuckyChef" << endl;
            else cout << "UnluckyChef" << endl;
        }
        
    }
    return 0;
}