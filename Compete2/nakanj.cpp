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
ll c[] = {-1, 1, -2, 2, -2, 2, -1, 1};
ll d[] = {-2, -2, -1, -1, 1, 1, 2, 2};

bool isin(ll i, ll j)
{
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

void solve()
{
    pair<ll, ll> start, end;
    string str1, str2;
    cin >> str1;
    start.f = str1[1] - '1';
    start.s = str1[0] - 'a';
    cin >> str1;
    end.f = str1[1] - '1';
    end.s = str1[0] - 'a';
    vector<vector<bool>> Visited(8, vector<bool>(8, false));
    queue<pair<pair<ll,ll>,ll>> Q;
    Q.push(mp(start,0));
    Visited[start.f][start.s] = true;
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        if(temp.f.f==end.f && temp.f.s==end.s){
            cout << temp.s << '\n';
            return;
        }
        for(ll i=0;i<8;++i)
        {
            ll a=temp.f.f+c[i],b = temp.f.s+d[i];
            if(isin(a,b)&&!Visited[a][b])
            {
                Visited[a][b] = true;
                Q.push(mp(mp(a,b),temp.s+1));
            }
        }
    }
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