#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define f first
#define s second
int main(){
    int n,x,y,i,j;
    cin >> n;
    vector< pair< int,pair<int,bool> > > Adj(n, pair<int, pair<int,bool> >(0,pair<int,bool>(0,false)));
    for(i=0;i<n;i++){
        cin >> x >> y;
        Adj[i].f=x;
        Adj[i].s.f=y;
        Adj[i].s.s=0;
    }
    sort(Adj.begin(),Adj.end());
    int count = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(i==j) continue;
            else if(Adj[i].s.f==Adj[j].f)
                Adj[j].s.s = true;
    }
    for(i=0;i<n;i++)
        if(Adj[i].s.s==false) count++;
    cout << count;
    return 0;
}