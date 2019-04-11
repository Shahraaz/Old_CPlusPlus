#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int j,i,arr[n],dp[n-k+1],minindex=0;
    long long sum = 0,min;
    for(i=0;i<n;i++) cin >> arr[i];
    for(i=0;i<k;i++) sum += arr[i];
    min = sum;minindex=0;
    for(i=1;i<=n-k;i++){
        sum += arr[k+i-1] - arr[i-1];
        if(sum<min){
            min = sum ;
            minindex = i;
        }
        // cout << sum << ' ' << min << '\n';
    } 
    cout << minindex + 1 ;
    return 0;
}