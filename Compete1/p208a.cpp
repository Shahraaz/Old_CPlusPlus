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
    ll i,n,x,y,j;
    cin >> n;
    vector< pair<ll,ll> > Vect;
    cin >> x;
    for(i=0;i<n-1;i++){
        cin >> y;
        Vect.pb(mp(min(x,y),max(x,y)));
        x = y;
    }
    sort(Vect.begin(),Vect.end());
    // for(i=0;i<n-1;i++)
    //   cout << Vect[i].f << ' ' << Vect[i].s << '\n';
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;++j){
            // cout << "Vect[j].f<Vect[i].s && Vect[j].s>Vect[i].s\n";
            // cout << Vect[j].f<< '<' << Vect[i].s << " && " << Vect[j].s<< '>' << Vect[i].s << '\n';
            if(Vect[j].f<Vect[i].s && Vect[j].s>Vect[i].s && Vect[i].f<Vect[j].f){
                cout << "yes";
                return 0;
            }
        }
    cout << "no";
    return 0;
}