#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t, ans,n,i,j;
    cin >> t ;
    while(t--)
    {
        cin >> n;
        long long int arr[n],count;
        for(i=0,count=0;i<n;i++)
        {
            cin >> arr[i];
            while(arr[i]%2==0)
            {
                count++;
                arr[i] /= 2;
            }
        }
        ans = count + 1;
        for(i=3;i<=1000;i+=2)
        {
            count = 0;
            for(j=0;j<n;j++)
                while(arr[j]%i==0)
                {
                    count++;
                    arr[j] /= i;
                }   
            ans *= count + 1;
        }
        for(j=n-1;j>=0;j--)
            if(arr[j]>2)
            {
                count = 1;
                for(i=0;i<j;i++)
                    if(arr[i]==arr[j])
                    {
                        count++;
                        arr[i] = 0;
                    }
                ans *= count + 1 ;    
            }
        cout << ans << endl;
    }
    return 0;
}
