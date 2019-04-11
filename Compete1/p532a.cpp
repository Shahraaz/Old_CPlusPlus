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
    ll i,n,k;
    cin >> n >> k;
    vector<ll> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    ll maxi = -1;
    for(ll j=0;j<k&&j<n;++j)
    {
        vector<bool> Mark(n,true);
        ll ans = 0;
        for(i=j;i<n;i+=k)
            Mark[i] = false;
        for(i=0;i<n;i++)
            if(Mark[i]) ans += Vect[i];
        maxi = max(maxi,abs(ans));
    }
    cout << maxi ;
    return 0;
}