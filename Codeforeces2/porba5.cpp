#include<iostream>
int min(int &a,int &b){
    return a > b ? b : a;
}
using namespace std;
int main(){
    int i,n,a,b,flag=0,cost=0;
    cin >> n >> a >> b;
    int arr[n];
    for(i=0;i<n;i++)
        cin >> arr[i];
    for(i=0;i<n/2;i++){
        if(arr[i]==0){
            if(arr[n-1-i]==0)
                continue;
            else if(arr[n-1-i]==1){
                flag = 1;
                break;
            }
            else if(arr[n-1-i]==2)
                cost += a ;
        }
        else if(arr[i]==1){
            if(arr[n-1-i]==1)
                continue;
            else if(arr[n-1-i]==0){
                flag = 1;
                break;
            }
            else if(arr[n-1-i]==2)
                cost += b;
        }
        else if(arr[i]==2){
            if(arr[n-1-i]==0)
                cost += a;
            else if(arr[n-1-i]==1)
                cost += b;
            else if(arr[n-1-i]==2)
                cost += 2*min(a,b);
        }
    }
    if(n&1) if(arr[n/2]==2) cost += min(a,b);
    if(!flag)
        cout << cost ;
    else cout << -1;
    return 0;
}