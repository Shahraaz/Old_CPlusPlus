#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n],i,step[n];
        cin >> arr[0];
        step[0] = arr[0] ;    
        long long int count = ceil((float)step[0]/k) - 1;
        for(i=1;i<n;i++){
            cin >> arr[i];
            step[i] = arr[i] - arr[i-1];
            count += ceil((float)step[i]/k) - 1;
        }
        cout << count << '\n';
    }
    return 0;
}