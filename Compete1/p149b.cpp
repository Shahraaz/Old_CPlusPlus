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
    ll n,i,x,y,min,max;
    min = 1e10;
    max = 1;
    cin >> n;
    vector< pair<ll,ll> > Segment(n+1);
    for(i=1;i<=n;i++){
        cin >> Segment[i].f >> Segment[i].s;
        if(Segment[i].f<min)
            min = Segment[i].f;
        if(Segment[i].s>max)
            max = Segment[i].s;
    }
    for(i=1;i<=n;i++){
        if(Segment[i].f==min && Segment[i].s==max){
            cout << i ;
            return 0;
        }
    }
    cout << -1;
    return 0;
}