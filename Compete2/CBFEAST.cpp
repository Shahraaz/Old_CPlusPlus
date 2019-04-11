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

int main(){
    fast;
    ll q,k,ans=0,c,d,ch;
    cin >> q >> k;
    deque< pair<ll,ll> > Dq;
    while(q--){
        cin >> ch;
        if(ch==1){
            cin >> c >> d;
            c = c^ans;
            // cout << "c d : " << c << ' ' << d << '\n';
            Dq.push_front(mp(c,d));
        }
        else if(ch==2){
            cin >> c >> d;
            c = c^ans;
            // cout << "c d : " << c << ' ' << d << '\n';
            Dq.push_back(mp(c,d));
        }
        else{
            cin >> c;
            c = c^ans;
            // cout << "c   : "<< c << '\n';
            ll maxsofar = 0,maxendinghere = 0;
            for(deque< pair<ll,ll> >::iterator it = Dq.begin();it!=Dq.end();it++){
                if(((*it).f<=c+k)&&((*it).f>=c-k))
                    maxendinghere += (*it).s;
                if(maxendinghere < 0)
                    maxendinghere = 0;
                else if(maxsofar < maxendinghere)
                    maxsofar = maxendinghere ;
            }
            ans = maxsofar;
            cout << ans << '\n';
        }
    }
    return 0;
}