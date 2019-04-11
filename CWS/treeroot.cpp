#include<iostream>
#include<algorithm>
using namespace std;
struct element
{
    int id;
    int sum;
};
int main()
{
    int i,t,n,j,ans;
    element arr[50];
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;
        for(i=0;i<n;i++)
        {
            cin >> arr[i].id >> arr[i].sum ;
            ans += arr[i].id - arr[i].sum ;
        }
        cout << ans << endl;
    }
    return 0;
}