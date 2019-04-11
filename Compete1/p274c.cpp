//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

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
    ll i,n,x,y;
    cin >> n;
    vector< pair<ll,ll> > Vect;
    for(i=0;i<n;i++){
        cin >> x >> y;
        Vect.pb(mp(x,y));
    }
    sort(Vect.begin(),Vect.end());
    ll date = 0;
    for(i=0;i<n;i++){
        if(Vect[i].s>=date){
            date = Vect[i].s;
        }
        else date = Vect[i].f;
    }
    cout << date;
    return 0;
}