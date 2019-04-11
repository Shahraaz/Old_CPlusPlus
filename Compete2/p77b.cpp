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

bool superl(ll str){
    ll i,c4=0,c7=0;
    for(;str;str/=10)
        if((str%10)==4) c4++;
        else c7++;
    return c4==c7;
}

int main(){
    fast;
    set<ll> lucky;
    ll i,j;
    lucky.insert(4);lucky.insert(7);
    for(i=2;i<10;i++){
        set<ll> lucky1;
        for(set<ll>::iterator it = lucky.begin();it!=lucky.end();it++){
            lucky1.insert((4+(*it)*10));
            lucky1.insert((7+(*it)*10));
        }
        for(set<ll>::iterator it = lucky1.begin();it!=lucky1.end();it++)
            lucky.insert(*it);
    }
    set<ll> super;
    for(set<ll>::iterator it = lucky.begin();it!=lucky.end();it++)
        if(superl(*it)){
            super.insert(*it);
            // cout << *it << '\n';
        }
    super.insert(4444477777);
    // cout << super.size() << '\n';
    ll str;
    cin >> str;
    cout << *(super.lower_bound(str));
    return 0;
}