//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = 0; i < (b); ++i)
#define trav(a, x) for (auto &a : v)
#define all(x) x.begin(), x.end()
const long long mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n, m, i, j;
    cin >> n >> m;
    vector<string> Map(n);
    vector<vector<ll>> Visited(n, vector<ll>(m, 0));
    for (i = 0; i < n; i++)
        cin >> Map[i];
    ll ans = 1,cnt=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (!Visited[i][j])
            {
                bool C = true;
                Visited[i][j] = ans;
                queue<pair<ll, ll>> Q;
                Q.push(mp(i, j));
                while (!Q.empty() && C)
                {
                    auto temp = Q.front();
                    // cout << temp.f << ' ' << temp.s << '\n';
                    Q.pop();
                    switch (Map[temp.f][temp.s])
                    {
                    case 'N':
                        if (temp.f != 0)
                        {
                            if (!Visited[temp.f - 1][temp.s])
                                Q.push(mp(temp.f - 1, temp.s));
                            else if( Visited[temp.f - 1][temp.s] != ans)
                                C = false;
                            Visited[temp.f - 1][temp.s] = ans;
                        }
                        break;
                    case 'S':
                        if (temp.f != (n - 1))
                        {
                            if (!Visited[temp.f + 1][temp.s] && Visited[temp.f + 1][temp.s] != ans)
                                Q.push(mp(temp.f + 1, temp.s));
                            else if( Visited[temp.f + 1][temp.s] != ans)
                                C = false;
                            Visited[temp.f + 1][temp.s] = ans;
                        }
                        break;
                    case 'W':
                        if (temp.s != 0)
                        {
                            if (!Visited[temp.f][temp.s-1] && Visited[temp.f][temp.s-1] != ans)
                                Q.push(mp(temp.f, temp.s - 1));
                            else if( Visited[temp.f][temp.s-1] != ans)
                                C = false;
                            Visited[temp.f][temp.s - 1] = ans;
                        }
                        break;
                    case 'E':
                        if (temp.s != (m - 1))
                        {
                            if (!Visited[temp.f][temp.s+1] && Visited[temp.f][temp.s+1] != ans)
                                Q.push(mp(temp.f, temp.s + 1));
                            else if( Visited[temp.f][temp.s+1] != ans)
                                C = false;
                            Visited[temp.f][temp.s + 1] = ans;
                        }
                        break;
                    }
                }
                ans++;
                if(C) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}