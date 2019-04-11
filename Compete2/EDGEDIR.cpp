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

vector<ll> degree;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(degree[a.f]==1&&degree[a.s]==1)
        return 0;
    if(degree[b.f]==1&&degree[b.s]==1)
        return 1;
    if(degree[a.f]==1||degree[a.s]==1)
        return 0;
    if(degree[b.f]==1||degree[b.s]==1)
        return 1;
    return (degree[a.f]+degree[a.s])<(degree[b.f]+degree[b.s]);
}

int main(){
    fast;
    ll t,n,m,i,x,y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> Indegree(n+1,0);degree.resize(n+1);
        vector< set<ll> > Und(n+1),Dir(n+1);
        vector< pair<ll,ll> > Edge(m),Edgeaux(m);
        for(i=0;i<m;i++){
            cin >> x >> y;
            Edge[i].f = x;
            Edge[i].s = y;
            degree[x]++;
            degree[x]++;
            Edgeaux[i].f = x;
            Edgeaux[i].s = y;
            Und[x].insert(y);
            Und[y].insert(x);
        }
        bool flag = true;
        if(m%2==1){
            cout << -1 << '\n';
            continue;
        }
        sort(Edge.begin(),Edge.end(),cmp);
        for(i=0;i<m;i++){
            if(Dir[Edge[i].f].count(Edge[i].s)==1||Dir[Edge[i].s].count(Edge[i].f)==1)
                continue;
            if(Und[Edge[i].f].size()>1){
                Dir[Edge[i].f].insert(Edge[i].s);
                Und[Edge[i].s].erase(Edge[i].f);
                Und[Edge[i].f].erase(Edge[i].s);
                ll k = *(Und[Edge[i].f].begin());
                Dir[Edge[i].f].insert(k);
                Indegree[Edge[i].f]++;
                Indegree[Edge[i].f]++;
                Und[k].erase(Edge[i].f);
                Und[Edge[i].f].erase(k);
            }
            else if(Und[Edge[i].s].size()>1){
                Dir[Edge[i].s].insert(Edge[i].f);
                Und[Edge[i].s].erase(Edge[i].f);
                Und[Edge[i].f].erase(Edge[i].s);
                ll k = *(Und[Edge[i].s].begin());
                Dir[Edge[i].s].insert(k);
                Indegree[Edge[i].s]++;
                Indegree[Edge[i].s]++;
                Und[k].erase(Edge[i].s);
                Und[Edge[i].s].erase(k);
            }
        }
        for(i=1;i<=n;i++)
            if(Indegree[i]%2!=0){
                flag = false;
                break;
            }
        if(flag)
            for(i=0;i<m;i++){
                if(Dir[Edgeaux[i].f].count(Edgeaux[i].s)!=0) cout << 0 << ' ';
                    else cout << 1 << ' ';
            }
        else cout << -1 ;
        cout << '\n';
    } 
    return 0;
}