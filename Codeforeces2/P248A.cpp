#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr1[100001], arr2[100001];
long long int st1[1<<18]={0},st2[1<<18]={0};
long long int constructSTUtil(int arr[], int ss, int se, long long int *st, int si) 
{ 
    if (ss == se) { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
    int mid = (ss+se)/2; 
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) + 
              constructSTUtil(arr, mid+1, se, st, si*2+2); 
    return st[si]; 
}
long long int getSumUtil(long long int *st, int ss, int se, int qs, int qe, int si) 
{ 
    if (qs <= ss && qe >= se) 
        return st[si]; 
    if (se < qs || ss > qe) 
        return 0; 
    int mid = (ss+se)/2; 
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    sort(arr2,arr2+n);
    constructSTUtil(arr1, 0, n-1, st1, 0);
    constructSTUtil(arr2, 0, n-1, st2, 0);
    int q,cs,l,r;
    cin >> q;
    while(q--){
        cin >> cs >> l >> r;
        if(cs==1) cout <<  getSumUtil(st1, 0, n-1, l-1, r-1, 0);
        else cout <<  getSumUtil(st2, 0, n-1, l-1, r-1, 0);
        cout << '\n';
    }
    return 0;
}