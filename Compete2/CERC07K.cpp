/*
    Author : Shahraaz
    Idea taken from : http://xoptutorials.com/index.php/2017/01/01/spojcerc07k/
    Real Author : zobayer
    Algo : BFS
*/
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
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = 0; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
const long long mod = 1000000007;
const long long size = 107;

vector<string> Map(size);
ll r, c;
ll Dist[size][size][16];
ll a[4] = {0, 0, 1, -1};
ll b[4] = {1, -1, 0, 0};

bool ingrid(pair<ll, ll> temp)
{
    return ((temp.f >= 0) && (temp.f < r) && (temp.s >= 0) && (temp.s < c));
}

ll BFS(pair<ll, ll> start)
{
    ll parentmask, childmask, px, py, i;
    queue<pair<pair<ll, ll>, ll>> Q;
    Q.push(mp(start, 0));
    pair<ll, ll> child;
    Dist[start.f][start.s][0] = 0;
    while (!Q.empty())
    {
        auto temp = Q.front();
        // cout << temp.f.f << ' ' << temp.f.s << ' ' << temp.s << '\n'; 
        Q.pop();
        px = temp.f.f;
        py = temp.f.s;
        parentmask = temp.s;
        for (i = 0; i < 4; i++)
        {
            child = mp(px + a[i], py + b[i]);
            if (ingrid(child) && Map[child.f][child.s] != '#')
            {
                childmask = parentmask;
                if (Map[child.f][child.s] == 'X')
                    return Dist[px][py][parentmask] + 1;
                if (Dist[child.f][child.s][childmask] == (-1))
                {
                    if ((Map[child.f][child.s] >= 'A') && (Map[child.f][child.s] <= 'Z'))
                    {
                        switch (Map[child.f][child.s])
                        {
                        case 'B':
                            if (parentmask & 1)
                                Q.push(mp(child, parentmask));
                            break;
                        case 'Y':
                            if (parentmask & 2)
                                Q.push(mp(child, parentmask));
                            break;
                        case 'R':
                            if (parentmask & 4)
                                Q.push(mp(child, parentmask));
                            break;
                        case 'G':
                            if (parentmask & 8)
                                Q.push(mp(child, parentmask));
                            break;
                        }
                    }
                    else if ((Map[child.f][child.s] >= 'a') && (Map[child.f][child.s] <= 'z'))
                    {
                        switch (Map[child.f][child.s])
                        {
                        case 'b':
                            childmask = parentmask | 1;
                            break;
                        case 'y':
                            childmask = parentmask | 2;
                            break;
                        case 'r':
                            childmask = parentmask | 4;
                            break;
                        case 'g':
                            childmask = parentmask | 8;
                            break;
                        }
                        Q.push(mp(child, childmask));
                        Dist[child.f][child.s][childmask] = Dist[px][py][parentmask] + 1;
                    }
                    else
                        Q.push(mp(child, parentmask));
                    Dist[child.f][child.s][parentmask] = Dist[px][py][parentmask] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll i, j, k;
    pair<ll, ll> start;
    cin >> r >> c;
    while (r && c)
    {
        for (i = 0; i < r; i++)
        {
            cin >> Map[i];
            for (j = 0; j < c; j++)
            {
                if (Map[i][j] == '*')
                    start = mp(i, j);
                for (k = 0; k < 16; k++)
                    Dist[i][j][k] = -1;
            }
        }
        ll dist = BFS(start);
        if (dist < 0)
            cout << "The poor student is trapped!\n";
        else
            cout << "Escape possible in " << dist << " steps.\n";
        cin >> r >> c;
    }
    return 0;
}