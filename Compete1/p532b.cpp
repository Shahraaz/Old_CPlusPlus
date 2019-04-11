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
    ll n,m,i;
    cin >> m >> n;
    vector<ll> a(n);
    vector<ll> Hash(100005,0);
    queue<ll> Set;
    ll discount = 0;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(Hash[a[i]]==0){
            discount++;
            Set.push(a[i]);
        }
        Hash[a[i]]++;
        if(discount==m)
        {
            cout << 1;
            for(ll j=0;j<m;j++)
            {
                ll temp = Set.front();
                Set.pop();
                Hash[temp]--;
                if(Hash[temp])
                    Set.push(temp);
                else discount--;
            }
        }
        else cout << 0;
    }
    return 0;
}