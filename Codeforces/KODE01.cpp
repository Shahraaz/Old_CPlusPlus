#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,temp,j,m,k,count;
        long long int result = 0;
        cin >> n >> m >> k;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
            arr[i] %= m;
            arr[i] = (arr[i]*arr[i])%m;
        }
        temp = 1<<n;
        count = 0;
        for(i=0;i<temp;i++){
            for(j=0,result=0;j<n;j++){
                if(i&(1<<j)){
                    result += arr[j];
                    result %= m;
                }
            }
            if(result==k)   count++; 
        }
        cout << count << '\n';       
    }
    return 0;
}