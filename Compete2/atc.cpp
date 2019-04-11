//Optimise Yourself
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

vector<string> Grid(402);
vector<vector<bool>> Visited(402, vector<bool>(402, false));
ll answer = 0;
ll n, m, i, j;
ll a[4] = {0,0,1,-1};
ll b[4] = {1,-1,0,0};

bool inside(pair<ll,ll> src)
{
    return (src.f<n) && (src.f>=0) && (src.s<m) && (src.s>=0) ;
}

pair<ll,ll> BFS(pair<ll, ll> src)
{
    pair<ll,ll>  t1(0,0);
    Visited[src.f][src.s] = true;
    if (Grid[src.f][src.s] == '#')
    {
        for(ll i=0;i<4;i++)
        {
            auto temp = mp(src.f+a[i],src.s+b[i]);
            // cout << temp.f << ' ' << temp.s << '\n';
            if (inside(temp) && (Grid[temp.f][temp.s] == '.' && !Visited[temp.f][temp.s])){
                temp = BFS(temp);
                t1.f += temp.f;
                t1.s += temp.s;
            }
        }
        t1.s++;
        return t1;
    }
    else
    {
        for(ll i=0;i<4;i++)
        {
            auto temp = mp(src.f+a[i],src.s+b[i]);
            // cout << temp.f << ' ' << temp.s << '\n';
            if (inside(temp) && (Grid[temp.f][temp.s] == '#' && !Visited[temp.f][temp.s])){
                temp = BFS(temp);
                t1.f += temp.f;
                t1.s += temp.s;
            }
        }
        t1.f++;
        return t1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> Grid[i];
    ll answer = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (!Visited[i][j]){
                auto temp = BFS(mp(i,j));
                answer += temp.f*temp.s;
            }
    cout << answer;
    return 0;
}