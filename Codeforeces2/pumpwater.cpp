#include<iostream>
#include<algorithm>
using namespace std;
int mreccr(int *arr,int l, int n){
    int index= max_element(arr + l, arr + n + 1) - arr;
    if(index==l||index==n)
        return 1;
    int temp1 = mreccr(arr,0, index-1);
    int temp2 = mreccr(arr,index + 1, n);
    return 1+min(temp1,temp2);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
    int tt,n,i,ans;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
    	    cin>>arr[i];
        cout<<mreccr(arr,0, n-1)<<'\n';
    }
    return 0;
}