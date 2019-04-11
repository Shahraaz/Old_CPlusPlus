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
    int i,n,m,x,y,z,j;
    cin >> n >> m;
    vector<int> Mark(n+1,0);
    while(m--){
        cin >> x >> y >> z;
        if(Mark[x]==0){
            if(Mark[y]!=1&&Mark[z]!=1) Mark[x] = 1;
            else if(Mark[y]!=2&&Mark[z]!=2) Mark[x] = 2;
            else if(Mark[y]!=3&&Mark[z]!=3) Mark[x] = 3;
        }
        if(Mark[y]==0){
            if(Mark[z]!=1&&Mark[x]!=1) Mark[y] = 1;
            else if(Mark[z]!=2&&Mark[x]!=2) Mark[y] = 2;
            else if(Mark[z]!=3&&Mark[x]!=3) Mark[y] = 3;
        }
        if(Mark[z]==0){
            if(Mark[y]!=1&&Mark[x]!=1) Mark[z] = 1;
            else if(Mark[y]!=2&&Mark[x]!=2) Mark[z] = 2;
            else if(Mark[y]!=3&&Mark[x]!=3) Mark[z] = 3;
        }
    }
    for(i=1;i<=n;i++)
        cout << Mark[i] << ' ';
    return 0;
}