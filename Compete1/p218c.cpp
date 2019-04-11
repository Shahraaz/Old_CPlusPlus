//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
ll nb,ns,nc,pb,ps,pc,rubel,cb,cs,cc,i;
ll fun(ll burgers){
    ll reqb = cb*burgers-nb, reqs = cs*burgers-ns, reqc = cc*burgers-nc ;
    ll rubreq = 0;
    if(reqb > 0) rubreq += reqb*pb;
    if(reqc > 0) rubreq += reqc*pc;
    if(reqs > 0) rubreq += reqs*ps; 
    return rubreq;
}
int main(){
    fast;
    string str;
    cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rubel;
    cb=cs=cc=0;
    for(int i=0;i<str.length();++i)
        switch(str[i]){
            case 'B' : cb++;
            break;
            case 'S' : cs++;
            break;
            case 'C' : cc++;
            break;
        }
    ll rubreq,answer,steps=100,low=0,high=1100000000000,f1,f2,rubreqmin=-1100000000000,mid;
    do{
        mid = low + (high-low)/2;
        rubreq = fun(mid) - rubel;
        if(rubreq==0){
            answer = mid;
            break;
        }
        else if(rubreq>0)
            high = mid - 1;
        else{
            low = mid + 1;
            else if(rubreq>=rubreqmin){
                answer = max(answer,mid);
                rubreqmin = rubreq;
            }
        }
        // Kcout << "answer " << answer <<'\n'; 
        // cout << "rubreq " << rubreq <<'\n';
        // cout << "rubreqmin " << rubreqmin <<'\n';
    }while(low<=high);
    cout << answer;
    return 0;
}