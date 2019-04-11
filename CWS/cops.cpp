#include<iostream>
using namespace std;
int main()
{
    int t,x,y,m,i,j,address,ans,left,right;
    cin >> t;
    while(t--)
    {
        int houses[101]={0};
        cin >> m >> x >> y ;
        while(m--)
        {
            cin >> address;
            left = (address-x*y > 0)? address-x*y : 1;
            right = (address+x*y < 101)? address+x*y : 100;
            for(;left<=right;left++)
                houses[left] = 1;
        }
        ans = 0;
        for(i=1;i<101;i++)
            if(!houses[i]) ans++;
        cout << ans << endl; 
    }
    return 0;
}