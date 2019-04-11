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
    // fast;
    int tree,capacity,i,x,y;
    cin >> tree >> capacity ;
    vector< pair<int,int> > day;
    for(i=0;i<tree;++i){
        cin >> x >> y ;
        day.pb(mp(x,y));
    }
    sort(day.begin(),day.end());
    vector<int> Done(day[tree-1].f+1,0);
    for(i=0;i<tree;i++){
/*        cout << "before\n";
        cout << "day[i].s " << day[i].s << '\n';
        cout << "Done[day[i].f] " << Done[day[i].f] << '\n'; 
*/        if(day[i].s+Done[day[i].f]<=capacity){
            Done[day[i].f] += day[i].s;
            day[i].s = 0;
        }
        else{
            int diff = capacity - Done[day[i].f];
            Done[day[i].f] += diff;
            day[i].s -= diff;
        }
/*        cout << "after\n";
        cout << "day[i].s " << day[i].s << '\n';
        cout << "Done[day[i].f] " << Done[day[i].f] << '\n';
        cout << "before\n";
        cout << "day[i].s " << day[i].s << '\n';
        cout << "Done[day[i].f+1] " << Done[day[i].f+1] << '\n'; 
*/        if(day[i].s+Done[day[i].f+1]<=capacity){
            Done[day[i].f+1] += day[i].s;
            day[i].s = 0;
        }
        else{
            int diff = capacity - Done[day[i].f+1];
            Done[day[i].f+1] += diff;
            day[i].s -= diff;
        }
/*        cout << "after\n";
        cout << "day[i].s " << day[i].s << '\n';
        cout << "Done[day[i].f+1] " << Done[day[i].f+1] << '\n';
*/    }
    ll count = 0;
    for(vector<int>::iterator it=Done.begin();it!=Done.end();++it)
        count += *it;
    cout << count;
    return 0;
}