#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void fun(int n){
    double low=0,high=n,mid;
    int n2=50;
    while(n2--){
        mid = low + (high-low)/2;
        if(abs(n-mid*(n-mid))<=1e-6){
            cout << setprecision(12)<< "Y "<<n-mid << ' ' << mid << endl;
            return ;
        }
        // cout << n-mid << ' ' << mid << endl;    
        if(mid*(n-mid)>n) high = mid-1;
        else low = mid+1;
    }
    cout << "N\n";
}
int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        fun(n);
    }
    return 0;
}