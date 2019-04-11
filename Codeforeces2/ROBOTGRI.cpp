//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = pow(2,31) - 1;
ll a[4] = {1, 0, -1, 0};
ll b[4] = {0, 1, 0, -1};
ll n;

bool isin(pair<ll, ll> T)
{
    return T.f >= 0 && T.f < n && T.s >= 0 && T.s < n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll i, j;
    cin >> n;
    vector<string> Grid(n);
    for (i = 0; i < n; i++)
        cin >> Grid[i];
    queue<pair<ll, ll>> Q;
    vector<vector<ll>> Dist(n, vector<ll>(n, 0));
    vector<vector<bool>> Visited(n, vector<bool>(n, 0));
    Q.push(mp(0, 0));
    Dist[0][0] = 1;
    Visited[0][0] = true;
    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        if (temp.f != 0)
            Dist[temp.f][temp.s] += Dist[temp.f - 1][temp.s];
        if (temp.s != 0)
            Dist[temp.f][temp.s] += Dist[temp.f][temp.s - 1];
        Dist[temp.f][temp.s] %= mod;
        if (temp.f + 1 == n && temp.s + 1 == n)
        {
            cout << Dist[temp.f][temp.s] << '\n';
            return 0;
        }
        for (i = 0; i < 2; ++i)
        {
            pair<ll, ll> Temp(temp.f + a[i], temp.s + b[i]);
            if (isin(Temp) && (!Visited[Temp.f][Temp.s]) && (Grid[Temp.f][Temp.s] == '.'))
            {
                Q.push(Temp);
                Visited[Temp.f][Temp.s] = true;
            }
        }
    }
    for (i = 0; i < n; i++){
        fill(Dist[i].begin(), Dist[i].end(), 0);
        fill(Visited[i].begin(), Visited[i].end(), false);
    }
    Q.push(mp(0, 0));
    Dist[0][0] = 1;
    Visited[0][0] = true;
    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        if (temp.f != 0)
            Dist[temp.f][temp.s] += Dist[temp.f - 1][temp.s];
        if (temp.s != 0)
            Dist[temp.f][temp.s] += Dist[temp.f][temp.s - 1];
        Dist[temp.f][temp.s] %= mod;
        if (temp.f + 1 == n && temp.s + 1 == n)
        {
            cout << "THE GAME IS A LIE" << '\n';
            return 0;
        }
        for (i = 0; i < 4; ++i)
        {
            pair<ll, ll> Temp(temp.f + a[i], temp.s + b[i]);
            if (isin(Temp) && (!Visited[Temp.f][Temp.s]) && (Grid[Temp.f][Temp.s] == '.'))
            {
                Q.push(Temp);
                Visited[Temp.f][Temp.s] = true;
            }
        }
    }
    cout << "INCONCEIVABLE";
    return 0;
}