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
    ll F, s, g, u, d;
    cin >> F >> s >> g >> u >> d;
    vector<bool> Visited(F+5,false);
    queue<pair<ll,ll>> Q;
    Q.push(mp(s,0));
    Visited[s] = true;
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        // cout << temp.f << ' ' << temp.s << '\n';  
        if(temp.f==g)
        {
            cout << temp.s << '\n';
            return 0 ;
        }
        if(temp.f+u<= F && !Visited[temp.f+u])
        {
            Visited[temp.f+u] = true;
            Q.push(mp(temp.f+u,temp.s+1));
        }
        if(temp.f-d>=0 && !Visited[temp.f-d])
        {
            Visited[temp.f-d] = true;
            Q.push(mp(temp.f-d,temp.s+1));
        }
    }
    cout << "use the stairs" ;
    return 0;
}