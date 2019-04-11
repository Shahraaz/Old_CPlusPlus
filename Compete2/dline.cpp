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
ll minnode(ll n, ll keyval[], bool mstset[]) { 
  ll mini = numeric_limits<ll>::max(); 
  ll mini_index;  
  for (ll i = 0; i < n; i++) { 
    if (mstset[i] == false && keyval[i] < mini) { 
      mini = keyval[i], mini_index = i; 
    } 
  } 
  return mini_index; 
} 
  
ll findcost(ll n, vector<vector<ll>> city) { 
  ll parent[n]; 
  ll keyval[n]; 
  bool mstset[n];
  for (int i = 0; i < n; i++) { 
    keyval[i] = numeric_limits<int>::max(); 
    mstset[i] = false;
  } 
  parent[0] = -1; 
  keyval[0] = 0; 
  for (int i = 0; i < n - 1; i++) { 
    ll u = minnode(n, keyval, mstset); 
    mstset[u] = true; 
    for (int v = 0; v < n; v++) { 
      if (city[u][v] && mstset[v] == false && 
          city[u][v] < keyval[v]) { 
        keyval[v] = city[u][v]; 
        parent[v] = u; 
      } 
    } 
  } 
  ll cost = 0; 
  for (int i = 1; i < n; i++)
    cost += city[parent[i]][i]; 
    return cost;
} 
int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n,i,s,y,e,j,p;
        cin >> n >> p;
        vector< pair< pair<ll,ll> , ll > > Vect;
        vector<ll> weight(n);
        for(i=0;i<n;i++){
            cin >> y >> s >> e;
            weight[i] = e - s;
            Vect.pb(mp(mp(y,s),e));
        }
        vector< vector<ll> > Dist(n,vector<ll>(n,0));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                Dist[i][j] = abs(Vect[i].f.f-Vect[j].f.f) + min ( min(abs(Vect[i].f.s-Vect[j].f.s),abs(Vect[i].s-Vect[j].s)),min(abs(Vect[i].f.s-Vect[j].s),abs(Vect[j].f.s-Vect[i].s)) );
                cout << Dist[i][j] << ' ';
            }
            cout << '\n';
        }
        ll maxcnt = 0;
        for(ll i=0;i<=(1<<n);i++){
            vector<bool> Marker(n,false);
            ll Weigth = 0,cnt = 0 ;
            for(ll j=0;j<n;j++)
                if(i&(1<<j)){
                    Weigth += weight[j];
                    Marker[j] = true;
                    cnt++;
                }
            if(Weigth<=p && (cnt>maxcnt)){   
            vector< vector<ll> > Dister(cnt,vector<ll>(cnt,0));
            ll cnt1=0;
            cout << "List ";
            for(ll jk=0;jk<n;jk++){
                if(Marker[jk]){
                    cout << jk << ' ';
                    ll cnt2 = 0;
                for(ll jj=0;jj<n;jj++){
                    if(Marker[jj]){
                        Dister[cnt1][cnt2] = Dist[jk][jj];
                        cnt2++;
                    }
                }
                cnt1++;
                }
            }
                cout << '\n';
                ll tt = findcost(cnt,Dister);
                cout << "weight " << Weigth << '\n' ;
                cout << "tt " << tt << '\n' ;
                if((tt+Weigth)<=p)
                    maxcnt = cnt;
            }
        }
        cout << maxcnt << '\n';
    }
    return 0;
}