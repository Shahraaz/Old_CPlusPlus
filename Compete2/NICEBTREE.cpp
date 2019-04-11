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

ll FUN(string str,ll &pos,ll end){
    if(pos==end) return -1;
    if(str[pos]=='l'){
        pos++;
        return 0;
    }
    pos++;
    ll t1 = FUN(str,pos,end) ;
    ll t2 = FUN(str,pos,end) ;
    return max(t1,t2) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        ll pos = 0;
        cout << FUN(str,pos,str.length()) << '\n';
    }
    return 0;
}