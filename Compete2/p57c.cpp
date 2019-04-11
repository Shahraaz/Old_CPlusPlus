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

int main(){
    fast;
    ll t,n,k;
    cin >> t;
    while(t--){
        cin >> n;
        bool flag = 1;
        for(k=3;k<=1000&&flag;k++){
            ll j = 1;
            ld m = 180.0/k;
            while((j<=(k-2))&&(m*(j)<=180)){
                if((m*(j))==n){
                    cout << k << '\n';
                    flag = 0;
                    break; 
                }
                j++;
            }
        }
        if(flag) cout << -1 << '\n';
    }
    return 0;
}