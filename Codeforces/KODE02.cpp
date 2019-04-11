#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll ConstructSegmentTree(ll* Segment,ll* arr,ll SegStart,ll SegEnd,ll Node){
    if(SegStart==SegEnd){
        Segment[Node] = arr[SegStart];
        return Segment[Node];
    }
    ll mid = (SegEnd + SegStart)/2;
    Segment[Node] = min(ConstructSegmentTree(Segment,arr,SegStart,mid,2*Node) , ConstructSegmentTree(Segment,arr,mid+1,SegEnd,2*Node+1));
    return Segment[Node];
}
int main() {
//    ios::sync_with_stdio(false);
  //  cin.tie(NULL);
    ll n,q,l,r,i,ch;
    cin >> n >> q;
    ll Segment[1<<18] = {0},arr[n+1],arr2[n];
    for(i=0;i<n;i++)
        cin >> arr[i+1];
    arr2[1] = abs(arr[2]-arr[1]); 
    for(i=2;i<=n-2;i++)
        arr2[i] = min(abs(arr[i+1]-arr[i]),abs(arr[i-1]-arr[i]));
    arr2[n-1] = abs(arr[n-1]-arr[n]); 
    ConstructSegmentTree(Segment,arr2,1,n-1,1);
    while(q--){
        cin >> ch;
        if(ch) cout << Segment[1] << '\n';
        else {
            cin >> l >> r;
            arr[l] = r;
            if(l==1)
                arr2[1] = abs(arr[1]-arr[2]);
            else if(l==n)
                arr2[n-1] = abs(arr[n]-arr[n-1]);
            else{
                i = l;
                arr2[i] = min(abs(arr[i+1]-arr[i]),abs(arr[i-1]-arr[i]));
                i = l-1;
                arr2[i] = min(abs(arr[i+1]-arr[i]),abs(arr[i-1]-arr[i]));
            }    
            ConstructSegmentTree(Segment,arr2,1,n-1,1);
        }
    }
	return 0;
}