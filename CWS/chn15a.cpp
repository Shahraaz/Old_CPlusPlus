#include<iostream>
using namespace std;
int main()
{
    int t,arr[100],k,i,n,count;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        k = k%7 ;
        count = 0;
        for(i=0;i<n;i++)
        {
            cin >>  arr[i];
            if((arr[i]+k)%7==0)
                count++; 
        }
        cout << count << endl;
    }
    return 0;
}