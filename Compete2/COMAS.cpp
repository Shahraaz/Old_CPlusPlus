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
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
ll t,n,a,b,c,d,i,j,t1,t2;
set<ll> Set;
void solve6(){
    ll arr[7];
    set<ll>::iterator it=Set.begin();
    for(i=1;i<=6;i++,it++)
        arr[i] = *it;
    vector< vector<ll> > Vect;
    vector< pair<ll,ll> > ans;
    map<ll,ll> mymap;
    for(j=1;j<=6;j++){
        cout << "? ";
        vector<ll> temp;
        for(i=1;i<=6;i++){
            if(i==j) continue;
            cout << arr[i] << ' ';
            temp.pb(arr[i]);
        }
        cout << endl;
        cin >> t1 >> t2;
        mymap[t2]++;
        ans.pb(mp(t1,t2));
        Vect.pb(temp);
    }
    map<ll,ll>::iterator min = mymap.begin();
    for(map<ll,ll>::iterator it = mymap.begin();it!=mymap.end();it++)
        if((min->s) > (it->s)) min = it;
    for(j=0;j<6;j++)
        if((ans[j].s)==(min->first)){
            for(i=0;i<5;i++)
                mymap[Vect[j][i]]++;
        }
    min = mymap.begin();
    for(map<ll,ll>::iterator it = mymap.begin()++;it!=mymap.end();it++){
        if((min->s) > (it->s)) min = it;
        // cout << it->f << ' ' << it->s << endl;
    }
    cout << "! " << min->f  << endl;
}
void solveeven(ll n){
    if(n==6){ 
        solve6();
        return;
    }
    cout << "? ";
    set<ll>::iterator it=Set.begin();
    for(i=0;i<5;i++,it++)
        cout << *it << ' ';
    cout << endl;
    cin >> t1 >> t2;
    Set.erase(t1);
    Set.erase(t2);
    solveeven(n-2);
}
void solve(){
    if(n&1){ // convert to even
        cout << "? 1 2 3 4 5" << endl;
        cin >> t1 >> t2;
        Set.erase(t1);
    }
    solveeven(n-(n&1));
}
int main(){
    fast;
    cin >> t;
    while(t--){
        cin >> n;
        Set.clear();
        for(i=1;i<=n;i++)
            Set.insert(i);
        solve();
    }
    return 0;
}