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
const long long size = 100005;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    vector<set<ll>> Adj(size);
    vector<ll> Sizes(size,0);
    queue<ll> Q;
    vector<bool> Deleted(size,false);
    ll i,n,m,k,a,b;
    cin >> n >> m >> k;
    for(i=0;i<m;i++)
    {
        cin >>  a >> b;
        Adj[a].insert(b);
        Adj[b].insert(a);
        if(a!=b)
            Sizes[a]++;
        Sizes[b]++;
    }
    for(i=0;i<n;i++)
        if(Sizes[i]<k)
            Q.push(i);
    ll res = n;
    while(res && !Q.empty())
    {  
        res--;
        ll temp = Q.front();
        Q.pop();
        Deleted[temp] = true;
        for(set<ll>::iterator it = Adj[temp].begin();it!=Adj[temp].end();++it)
        {
            if(Deleted[*it]) continue;
            Sizes[*it]--;
            if(Sizes[*it]<k)
                Q.push(*it);
        }
    }
    cout << res;
    return 0;
}