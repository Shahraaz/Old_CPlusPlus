//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int a = -1, b = -1,length = mod,l,r;
    map<int,int> Map;
    for(l = r = 0;r<n;r++)
    {
        Map[arr[r]]++;
        while(true)
        {
            Map[arr[l]]--;
            if(Map[arr[l]]==0) Map.erase(arr[l]);
            if(Map.size()<k)    break;
            else l++;
        }
        Map[arr[l]]++;
        if((r-l+1)<length && Map.size()>=k)
        {
            length = r - l + 1;
            a = l + 1;
            b = r + 1;
        }
    }
    cout << a << ' ' << b;
    return 0;
}