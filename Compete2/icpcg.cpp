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
    ll t,k,arr[7],i,j,mini,cnt;
    cin >> t;
    while(t--){
        cin >> k;
        cnt = 0;
        for(i=0;i<7;i++){
            cin >> arr[i];
            cnt += (arr[i]);
        }
        mini = 1000000000000;
        for(j=0;j<7;j++){
            ll k2,temp = 0,cnt1=0;
            for(i=j;i<7;i++){
                if(temp>=k) break;
                temp += arr[i];
                cnt1++;
                if(temp>=k) break;
            }
            while(true){
                for(i=0;i<7;i++){
                    if(temp>=k) break;
                    temp += arr[i];
                    cnt1++;
                    if(temp>=k) break;
                }
                if(temp>=k) break;
                cnt1 += ((k-temp)/cnt)*7;
                temp += ((k-temp)/cnt)*cnt;
                if(temp>=k) break;
            }
            mini = min(mini,cnt1);
        }
        cout << mini << '\n';
    }
    return 0;
}