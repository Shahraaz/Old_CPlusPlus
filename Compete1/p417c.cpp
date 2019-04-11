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

int main(){
    fast;
    ll mid,i,n,budget,x,low,high;
    cin >> n >> budget;
    vector<ll> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    low = 0;high = n;
    ll sum,answer=0,count=0;
    while(low<=high){
        mid = low + (high-low)/2;
        sum = 0;
        priority_queue< ll,vector<ll>,greater<ll> > minHeap;
        for(i=0;i<n;i++)
            minHeap.push(Vect[i] + (i+1)*mid);
        for(i=0;i<mid;i++){ 
            sum += minHeap.top();
            minHeap.pop();
        }
        if(sum==budget){
            count = mid;
            answer = sum;
            break;
        }
        else if(sum<budget){
            low = mid+1;
            count = mid;
            answer = sum;
        }
        else{
            if(low==high) break;
            high = mid ;
        }
    }
    cout << count << ' ' << answer ;
    return 0;
}