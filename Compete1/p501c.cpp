//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll n, m, i,x,y,maxsum;
    cin >> n >> m;
    vector<ll> Vect(n,0);
    for(i=maxsum=0;i<n;i++){
        cin >> x >> y;
        Vect[i]= x - y;
        maxsum += y;
    }
    sort(Vect.begin(),Vect.end());
    if(maxsum>m) cout << -1;
    else{
        ll answer = n;
        for(i=0;i<n;i++){
            maxsum += Vect[i];
            if(maxsum>m) break;
            answer--;
        }
        cout << answer;
    }
    return 0;
}