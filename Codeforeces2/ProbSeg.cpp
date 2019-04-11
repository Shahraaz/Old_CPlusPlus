#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
bool isPerfectSquare(long double x){
    long double sr = sqrt(x);
    return ((sr-floor(sr))==0);
}
ll ConstructSegmentTree(ll* Segment,ll * SegmentResult,ll* arr,ll SegStart,ll SegEnd,ll Node){
    if(SegStart==SegEnd){
        Segment[Node] = arr[SegStart];
        if(isPerfectSquare(Segment[Node]))
            SegmentResult[Node] = 1;
        return Segment[Node];
    }
    ll mid = (SegEnd + SegStart)/2;
    Segment[Node] = ConstructSegmentTree(Segment,SegmentResult,arr,SegStart,mid,2*Node) & ConstructSegmentTree(Segment,SegmentResult,arr,mid+1,SegEnd,2*Node+1);
    SegmentResult[Node] = SegmentResult[Node*2] + SegmentResult[Node*2+1];
    ll i,j,temp = arr[mid],temp2,arr2[SegEnd - mid];
    arr2[0] = arr[mid+1];
    for(i=1;i<SegEnd - mid;i++)
        arr2[i] = arr2[i-1] & arr[mid+1+i];
    for(i=mid;i>=SegStart;i--){
        temp = temp & arr[i];
        for(j=0;j<SegEnd - mid;j++)
            if(isPerfectSquare(temp & arr2[j]))
                SegmentResult[Node]++;
    }
    return Segment[Node];
}
ll GetResult(ll *SegmentResult,ll* arr,ll QueryStart,ll QueryEnd,ll SegStart,ll SegEnd,ll Node){
    if(SegStart > SegEnd | SegStart > QueryEnd | SegEnd < QueryStart)
        return 0;
    if(QueryStart <= SegStart & SegEnd <= QueryEnd){
        ll temp = SegmentResult[Node],arr2[QueryEnd-SegEnd+1],j,i,temp2 = arr[SegEnd];
        if(SegEnd<QueryEnd){
            arr2[0] = arr[SegEnd+1];
            for(i=1;i<QueryEnd - SegEnd;i++)
                arr2[i] = arr2[i-1] & arr[SegEnd+1+i];
            for(i=SegEnd;i>=SegStart;i--){
                temp2 = temp2 & arr[i];
                for(j=0;j<QueryEnd - SegEnd;j++)
                    if(isPerfectSquare(temp2 & arr2[j]))
                        temp++;
            }
        }
        return temp;
    }
    ll mid = (SegEnd + SegStart)/2,temp;
    return  GetResult(SegmentResult,arr,QueryStart,QueryEnd,SegStart,mid,Node*2) 
         + GetResult(SegmentResult,arr,QueryStart,QueryEnd,mid+1,SegEnd,Node*2+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,q,l,r,i;
    cin >> t;
    while(t--){
        cin >> n >> q;
        ll Segment[1<<18] = {0},SegmentResult[1<<18] = {0},arr[n+1];
        for(i=0;i<n;i++)
            cin >> arr[i+1];
        ConstructSegmentTree(Segment,SegmentResult,arr,1,n,1);
        while(q--){
            cin >> l >> r;
            cout << GetResult(SegmentResult,arr,l,r,1,n,1) << '\n' ;
        }
    }
	return 0;
}
