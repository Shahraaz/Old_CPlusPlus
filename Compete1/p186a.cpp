//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
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
const long long mod = 1000000007;
string fun(ll n){
    string str = to_string(n),n1,n2;
    for(ll i=0;i<str.length();i++){
        if(i==str.length()-1)   n2 += str[i];
        else if(i==str.length()-2)   n1 += str[i];
        else {
            n1 += str[i];
            n2 += str[i];
        }
    }
    n1 = min(n1,n2);
    return n1=="-0" ? "0" : n1;
}
int main(){
    fast;
    ll n ;
    cin >> n;
    if(n>0) cout << n;
    else cout << fun(n);
    return 0;
}