#include<iostream>
using namespace std;
int main()
{
    int t,n,arr[101];
    unsigned long long int c ,sum;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        sum = 0;
        while(n--)
        {
            cin >> arr[n];
            sum+=arr[n];
        }
        if(sum<=c) cout << "Yes" << endl;
        else cout << "No" << endl ;
    }
    return 0;
}