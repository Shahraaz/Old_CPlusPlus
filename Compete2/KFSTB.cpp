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
ll t;
vector<vector<ll>> Child(10005), Parent(10005);
vector<ll> Ways(10005);

ll dfs(ll s)
{
    if(Ways[s]) return Ways[s];
    for (ll x : Child[s])
    {
        Ways[x] = dfs(x);
        Ways[s] += Ways[x];
        Ways[s] %= mod;
    }
    return Ways[s];
}

void solve()
{
    ll c, b, s, e, f;
    cin >> c >> b >> s >> t;
    for(ll i=0;i<c;++i)
    {
        Parent[i].clear();
        Child[i].clear();
    }
    fill(Ways.begin(),Ways.end(),0);
    s--;
    t--;
    while (b--)
    {
        cin >> e >> f;
        e--;
        f--;
        Child[e].pb(f);
        Parent[f].pb(e);
    }
    Ways[t] = 1;
    Ways[s] = dfs(s);
    cout << Ways[s] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}