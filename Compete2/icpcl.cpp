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

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return (a.s==b.s) ? (a.f<b.f) : (a.s<b.s);
}

int main(){
    fast;
    ll i,n,k,x,y;
    cin >> n >> k;
    vector< pair<ll,ll> > Choice;
    vector<bool> Marker(k+1,0);
    ll sum = 0;
    for(i=0;i<n;i++){
        cin >> x ;
        Choice.pb(mp(x,0));
    }
    for(i=0;i<n;i++){
        cin >> x ;
        Choice[i].s = x;
    }
    ll sum2 = 0,done=0;
    sort(Choice.begin(),Choice.end());
    for(i=n-1;i>=0;i--){
        if(Marker[Choice[i].f]==false){
            Choice[i].s = 100000000000;
            done++;
            Marker[Choice[i].f] = true;
        }    
    }
    sort(Choice.begin(),Choice.end(),cmp);
    i = 0;
    for(;done<k;done++,i++)
        sum += Choice[i].s;
    cout << sum;
    return 0;
}