//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=0;i<(b);++i)
#define trav(a,x) for(auto& a : v)
#define all(x) x.begin(),x.end()
const long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,x,y,i,j;
    string boul;
    cin >> n;
    while(n!=0){
        vector< vector < pair<ll,ll> > > Child(n+1);
        vector< vector < pair<ll,ll> > > Parent(n+1);
        for(i=1;(i<=n);i++){
            cin >> x >> boul;
            if(boul=="true"){
                Child[i].pb(mp(x,1));
                Parent[x].pb(mp(i,1));
            } 
            else{
                Child[i].pb(mp(x,0));
                Parent[x].pb(mp(i,0));
            } 
        }
        y = 1;
        vector<bool> Visited(n+1,false);
        vector<ll> Truth(n+1,-1);
        for(i=1;i<=n && y;i++){
            {
                Visited[i] = true;
                if(Truth[i] == -1)
                    Truth[i] = 1;
                queue<ll> Q;
                Q.push(i);
                while(!Q.empty() && y){
                    ll temp = Q.front();
                    Q.pop();
                    for(pair<ll,ll> child : Child[temp])
                        {
                            if(!Visited[child.f]) Q.push(child.f);
                            Visited[child.f] = true;
                            if(Truth[temp]==1){
                                if(child.s){
                                    if(Truth[child.f]==0){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[child.f] = 1;
                                }
                                else {
                                    if(Truth[child.f]==1){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[child.f] = 0;
                                }
                            }
                            else{
                                if(child.s){
                                    if(Truth[child.f]==1){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[child.f] = 0;
                                }
                                else {
                                    if(Truth[child.f]==0){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[child.f] = 1;
                                }
                            }
                        }
                    for(pair<ll,ll> parent : Parent[temp])
                        {
                            if(!Visited[parent.f]) Q.push(parent.f);
                            Visited[parent.f] = true;
                            if(Truth[temp]==1){
                                if(parent.s){
                                    if(Truth[parent.f]==0){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[parent.f] = 1;
                                }
                                else {
                                    if(Truth[parent.f]==1){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[parent.f] = 0;
                                }
                            }
                            else{
                                if(parent.s){
                                    if(Truth[parent.f]==1){
                                        y = 0;
                                        break;
                                    }
                                    else Truth[parent.f] = 0;
                                }
                                else {
                                    if(Truth[parent.f]==0){
                                        y = 0;
                                        break;
                                    }
                                    else  Truth[parent.f] = 1;
                                }
                            }
                        }
                }
            }
            if(y==0) break;
        }
        if(y==0) cout << "PARADOX\n";
        else  cout << "NOT PARADOX\n";
        cin >> n;
    } 
    return 0;
}