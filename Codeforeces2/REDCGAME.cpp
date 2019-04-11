#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t,n,k,i,arr[51],count,sum,temp;
    cin >> t;
    while(t--){
        cin >> n >> k;
        count = sum = 0;
        for(i=0;i<n;i++){
            cin >> temp;
            if(temp>k) arr[count++] = temp;
            else sum += temp;
        }
        for(i=0;i<count-2;i++){
            arr[i+1] += arr[i] - k;
            arr[i] = k;
            sum += k;
        }
        if(i>=0){
            sum += a
        }
    }
    return 0;
}