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
    ll a[3],count=0;
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    if(a[0]>=3 && a[1]>=3 && a[2]>=3){ // mixable
        ll ans1 = a[0];
        ans1 += (a[1]-a[0])/3 + (a[2]-a[0])/3; // perfect mixing
        ll ans2 = a[0]/3 + a[1]/3 + a[2]/3 ; // not mixing at all
        ll ans3 = a[1]/3 + a[2]/3;
        a[1] %= 3;
        a[2] %= 3;
        sort(a,a+3);
        ans3 += a[0];
        cout << max(ans1,max(ans2,ans3));  
    }
    else cout << a[0]/3 + a[1]/3 + a[2]/3;
    return 0;
}