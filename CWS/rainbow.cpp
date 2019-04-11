#include<iostream>
using namespace std;
int main()
{
    int i,j,t,n,arr[100],k,flag,value;
    cin >> t;
    while(t--)
    {
        int count[11] = {0};
        cin >> n;
        for(i=0;i<n;i++)
        {    
            cin >> arr[i];
            count[arr[i]]++;
        }
        flag = value = 1;
        for(i=0;i<=n/2;i++)
            if(arr[i]>7|arr[i]!=arr[n-1-i])
            {
                flag = 0;
                break;
            }
        if(flag)
            for(i=0;i<=n/2;i++)
                if(arr[i]==value) ;
                else if(arr[i]==value+1) value++;
                else
                {
                    flag = 0;
                    break;
                } 
        if(flag)
            for(i=1;i<=7;i++)
                if(!count[i])
                {
                    flag = 0;
                    break;
                }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}