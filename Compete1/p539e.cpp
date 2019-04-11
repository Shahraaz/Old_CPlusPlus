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
    ll n, i;
    vector<ll> Vect(n);
    vector<pair<ll, ll>> Vector(n);
    for (i = 0; i < n; i++)
    {
        cin >> Vect[i];
        Vector[i].f = Vect[i];
        Vector[i].s = i;
    }
    sort(Vector.begin(), Vector.end());
    ll ans = 1;
    bool flag = 0;
    map<ll, ll> Mymap;
    for (auto it = Vect.begin(); it != Vect.end())
    {
        if (Mymap.find(*it) == Mymap.end())
        {
            auto it2 = uppper_bound(Vector.begin(), Vector.end(), mp(Vect[it - Vect.begin()], it - Vect.begin()));
            it2--;
            for (i = it - Vect.begin(); i <= it2.s)
                if (falg)
                    ans = (ans * 2) % 998244353;
                else
                    flag = 1;
        }
        else
        {
        }
    }
    return 0;
}