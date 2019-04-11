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
ll c, r;
ll a[4] = {0, 0, 1, -1};
ll b[4] = {1, -1, 0, 0};
bool isin(pair<ll, ll> A)
{
    return A.f >= 0 && A.f < r && A.s >= 0 && A.s < c;
}
void solve()
{
    ll i, j;
    cin >> c >> r;
    vector<string> Lab(r);
    for (i = 0; i < r; i++)
        cin >> Lab[i];
    // cout << "Here\n";
    vector<vector<bool>> Visited(r, vector<bool>(c, false));
    vector<vector<ll>> Dist(r, vector<ll>(c));
    pair<pair<ll, ll>, ll> maxi;
    maxi = mp(mp(0, 0), -1);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (Lab[i][j] == '.' && !Visited[i][j])
            {
                queue<pair<ll, ll>> Q;
                Q.push(mp(i, j));
                Visited[i][j] = true;
                Dist[i][j] = 0;
                while (!Q.empty())
                {
                    auto temp = Q.front();
                    Q.pop();
                    if (Dist[temp.f][temp.s] > maxi.s)
                    {
                        maxi.s = Dist[temp.f][temp.s];
                        maxi.f = temp;
                    }
                    for (ll k = 0; k < 4; k++)
                    {
                        pair<ll, ll> x(temp.f + a[k], temp.s + b[k]);
                        if (isin(x) && !Visited[x.f][x.s] && Lab[x.f][x.s] == '.')
                        {
                            Visited[x.f][x.s] = true;
                            Dist[x.f][x.s] = Dist[temp.f][temp.s] + 1;
                            Q.push(x);
                        }
                    }
                }
            }
    // cout << maxi.f.f << ' ' << maxi.f.s << ' ' << maxi.s << "'\n'";
    queue<pair<ll, ll>> Q;
    vector<vector<ll>> Dist1(r, vector<ll>(c));
    vector<vector<bool>> Visited1(r, vector<bool>(c, false));
    Dist1[(maxi.f.f)][(maxi.f.s)] = 0;
    Q.push(maxi.f);
    Visited1[maxi.f.f][maxi.f.s] = true;
    maxi.s = 0;
    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        if (Dist1[(temp.f)][(temp.s)] > maxi.s)
        {
            maxi.s = Dist1[(temp.f)][(temp.s)];
            maxi.f = temp;
        }
        for (ll i = 0; i < 4; i++)
        {
            pair<ll, ll> x(temp.f + a[i], temp.s + b[i]);
            if (isin(x) && !Visited1[x.f][x.s] && Lab[x.f][x.s] == '.')
            {
                Visited1[x.f][x.s] = true;
                Dist1[(x.f)][(x.s)] = Dist1[(temp.f)][temp.s] + 1;
                Q.push(x);
            }
        }
    }
    cout << "Maximum rope length is " << maxi.s << ".\n";
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