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
typedef int ll;
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

ll modmul(ll a, ll b)
{
    return (a * b) % mod;
}
struct MATRIX
{
    ll m[2][2];
};

ll powe(ll base, ll index)
{
    if (index == 0)
        return 1;
    ll temp = powe(base, index / 2);
    temp = modmul(temp, temp);
    if (index & 1)
        temp = modmul(temp, base);
    return temp;
}

MATRIX MUL(MATRIX a, MATRIX b)
{
    MATRIX result;
    result.m[0][0] = (modmul(a.m[0][0], b.m[0][0]) + modmul(a.m[0][1], b.m[1][0])) % mod;
    result.m[0][1] = (modmul(a.m[0][0], b.m[0][1]) + modmul(a.m[0][1], b.m[1][1])) % mod;
    result.m[1][0] = (modmul(a.m[1][0], b.m[0][0]) + modmul(a.m[1][1], b.m[1][0])) % mod;
    result.m[1][1] = (modmul(a.m[1][0], b.m[0][1]) + modmul(a.m[1][1], b.m[1][1])) % mod;
    return result;
}

MATRIX power(MATRIX M, ll index)
{
    if (index == 0)
    {
        MATRIX t;
        t.m[0][0] = 1;
        t.m[0][1] = 0;
        t.m[1][0] = 0;
        t.m[1][1] = 1;
        return t;
    }
    MATRIX temp;
    temp = power(M, index / 2);
    temp = MUL(temp, temp);
    if (index & 1)
        temp = MUL(temp, M);
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t, i, d, T;
    cin >> t;
    while (t--)
    {
        cin >> i >> d >> T;
        ll cost = modmul(d, powe(i, mod - 2));
        MATRIX M;
        M.m[0][0] = modmul(2, cost);
        M.m[0][1] = (mod - 1);
        M.m[1][0] = 1;
        M.m[1][1] = 0;
        M = power(M, T - 1);
        // cout << cost << '\n';
        // cout << M.m[0][0] << ' ' << M.m[0][1] << '\n';
        // cout << M.m[1][0] << ' ' << M.m[1][1] << '\n';
        cout << modmul(i, (modmul(M.m[0][0], cost) + M.m[0][1]) % mod) << '\n';
    }
    return 0;
}