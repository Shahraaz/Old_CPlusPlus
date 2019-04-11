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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        bool value = (n%2==0) || (m%2==0);
        if(value) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}