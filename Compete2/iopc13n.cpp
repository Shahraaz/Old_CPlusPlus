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
    ll n, q, u, i, x, y;
    cin >> n >> q;
    cin >> u;
    vector<vector<ll>> Child(100005), Parent(100005);
    vector<ll> Level(100005);
    vector<bool> Visited(100005, false);
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        Child[x].pb(y);
        Child[y].pb(x);
    }
    queue<pair<ll, ll>> Q;
    Q.push(mp(u, 1));
    Level[u] = 1;
    while (!Q.empty())
    {
        auto temp = Q.front();
        Visited[temp.f] = true;
        Q.pop();
        for (ll x : Child[temp.f])
        {
            if (!Visited[x])
            {
                Parent[x].pb(temp.f);
                Level[x] = temp.s + 1;
                Q.push(mp(x, Level[x]));
            }
        }
    }
    while (q--)
    {
        queue<ll> Q1;
        cin >> x >> y;
        bool found = false;
        // cout << "x " << x << " y " << y << '\n';
        if (Level[x] == Level[y])
            cout << "0" << '\n';
        else if (Level[x] > Level[y])
        {
            Q1.push(x);
            while (!Q1.empty()&&!found)
            {
                auto temp = Q1.front();
                // cout << temp << ' ' ;
                Q1.pop();
                if (temp == y)
                {
                    cout << "1" << '\n';
                    found = true;
                }
                if (Level[temp] > Level[y])
                    for (ll x : Parent[temp])
                        Q1.push(x);
            }
            // cout << '\n';
            if(!found) cout << "0" << '\n';
        }
        else
        {
            swap(x,y);
            Q1.push(x);
            while (!Q1.empty()&&!found)
            {
                auto temp = Q1.front();
                Q1.pop();
                // cout << temp << ' ' ;
                if (temp == y)
                {
                 cout << "-1" << '\n';
                    found = true;
                }
                if (Level[temp] > Level[y])
                    for (ll x : Parent[temp])
                        Q1.push(x);
            }
            // cout << '\n';
            if(!found) cout << "0" << '\n';
        }
    }
    return 0;
}