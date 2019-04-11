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
    ll i,n,t;
    cin >> n >> t;
    vector<ll> Book(n+1,0),ctime(n+1,0);
    for(i=1;i<=n;i++){
        cin >> Book[i];
        ctime [i] += ctime[i-1] + Book[i];
    }
/*    for(i=0;i<=n;i++)
        cout << ctime[i] << ' '; cout << '\n';
*/    ll nmax = 0;
    for(vector<ll>::iterator it = ctime.begin();it!=ctime.end();it++){
        nmax = max(nmax,(ll)(upper_bound(it,ctime.end(),*it+t)-it)-1);
    }
    cout << nmax;
    return 0;
}