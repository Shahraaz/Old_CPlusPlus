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
#define end {cout << -1;return 0;}
const long long mod = 1000000007;



int main(){
    fast;
    ll i,n,j,k,x,y;
    cin >> n >> k;
    vector< vector<bool> > Adj(n+1, vector<bool>(n+1,false));
    vector< int > Degree(n+1,0);
    vector<bool> Mark(n+1,1);
    while(k--){
        cin >> x >> y;
        Adj[x][y] = true; 
        Adj[y][x] = true;
        Degree[x]++;Degree[y]++;
    }
    vector< vector<int> > Vect,loner,duplet;
    for(i=1;i<=n;i++){
        if(Mark[i]){
            vector<int> temp;
            temp.pb(i);
            Mark[i] = false;
            vector<int> Frontier;
            Frontier.pb(i);
            while(Frontier.size()){
                vector<int> t;
                for(k=0;k<Frontier.size();k++)
                    for(j=1;j<=n;++j)
                        if(Adj[Frontier[k]][j]&&Mark[j]){ 
                            temp.pb(j);
                            t.pb(j);
                            Mark[j] = false;
                        }
                Frontier = t;
            }
            if(temp.size()>3)
                end
            else if(temp.size()==3)
                Vect.pb(temp);
            else if(temp.size()==2)
                duplet.pb(temp);
            else
                loner.pb(temp);
        }
    }
    if(duplet.size()>loner.size()) end
    else if((loner.size()-duplet.size())%3) end
    for(ll i=0;i<Vect.size();i++){
        for(j=0;j<3;j++)
            cout << Vect[i][j] << ' ';
        cout << '\n';
    }
    k = 0;
    for(i=0;i<duplet.size();i++){
        for(j=0;j<2;j++)
            cout << duplet[i][j] << ' ';
        cout << loner[k][0] << '\n';
        k++;
    }
    for(;k<loner.size();){
        for(j=0;j<3;k++,j++)
            cout << loner[k][0] << ' ';
        cout << '\n';
    }
    return 0;
}