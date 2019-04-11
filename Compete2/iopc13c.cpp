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

bool solve()
{
    ll i, n, r1, r2, a, b;
    vector<vector<ll>> Adj1(100005), Adj2(100005),Lv1Adj(100005),Lv2Adj(100005);
    vector<bool> Visited1(100005,false),Visited2(100005,false);
    cin >> n;
    cin >> r1;
    for (i = 1; i < n ; i++)
    {
        cin >> a >> b;
        Adj1[a].pb(b);
        Adj1[b].pb(a);
    }
    cin >> r2;
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        Adj2[a].pb(b);
        Adj2[b].pb(a);
    }
    queue<pair<ll,ll>> Q;
    Q.push(mp(r1,1));
    while(!Q.empty())
    {
        ll cnt = 0;
        auto temp = Q.front();
        Q.pop();
        Visited1[temp.f] = true;
        for(ll x : Adj1[temp.f])
            if(!Visited1[x])
            {
                Q.push(mp(x,temp.s+1));
                cnt++;
            }
        Lv1Adj[temp.s].pb(cnt);   
    }
    Q.push(mp(r2,1));
    while(!Q.empty())
    {
        ll cnt = 0;
        auto temp = Q.front();
        Q.pop();
        Visited2[temp.f] = true;
        for(ll x : Adj2[temp.f])
            if(!Visited2[x])
            {
                Q.push(mp(x,temp.s+1));
                cnt++;
            }
        Lv2Adj[temp.s].pb(cnt);   
    }
    for(i=0;i<=n;i++)
    {
        if(Lv1Adj[i].size()!=Lv2Adj[i].size())
            return false;
        sort(Lv1Adj[i].begin(),Lv1Adj[i].end());
        sort(Lv2Adj[i].begin(),Lv2Adj[i].end());
        for(ll j = 0;j<Lv1Adj[i].size();j++)
            if(Lv1Adj[i][j]!=Lv2Adj[i][j])
                return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}