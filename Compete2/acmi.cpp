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
map<ll,ll> Answer;
ll getidx(ll start,ll end)
{
    return ((start + end + 1)* (start + end)/2 + end);
}
ll *Vect;
ll i,n,k;
pair<ll,ll> fun(ll start,ll end){
    if(end-start+1<k) return mp(1<<30,1<<30);
    if(end-start+1==k) return mp(Vect[end]-Vect[start],end-start+1);
    ll idx = getidx(start,end);
    if(Answer.find(idx) == Answer.end()){
        Answer[idx] = Vect[end]-Vect[start];
        cout << "Start " << start << " end " << end  << ' ' << Answer[idx] << endl;
        for(ll i=start+k-1;i<=end-k;i++){
            pair<ll,ll> temp = fun(i+1,end);
            Answer[idx] = min(Answer[idx],max(Vect[i]-Vect[start],temp.f));
        }
    }
    return mp(Answer[idx],end-start+1);
}
int main(){
    fast;
    cin >> n >> k;
    Vect = new ll[n];
    for(i=0;i<n;i++)
        cin >> Vect[i];
    sort(Vect,Vect+n);
    cout << fun(0,n-1).f;
    return 0;
}