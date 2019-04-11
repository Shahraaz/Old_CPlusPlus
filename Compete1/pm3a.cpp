//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
typedef long double ld ;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    int a,b,n,i,j;
    cin >> n;
    vector<int> Vect(101,0);
    for(j=0;j<n;j++){
        cin >> a;
        for(i=0;i<a;i++){
            cin >> b;
            Vect[b]++;
        }
    }
    for(i=0;i<101;i++)
        if(Vect[i]==n) cout << i << ' ';
    return 0;
}