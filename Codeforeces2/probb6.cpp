#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int n,i ;
    cin >> n ;
    if(n==1|n==2) cout << "No" ;
    else{
        vector<int> even,odd;
        int sumeven = 0,sumodd = 0;
        for(i=1;i<=n;i++){
            if(i&1) odd.push_back(i);
            else even.push_back(i);
        }
        cout << "Yes\n";
        cout << even.size() << ' ';
        for(i=0;i<even.size();sumeven += even[i++])
            cout << even[i] << ' ';
        cout << '\n';    
        cout << odd.size() << ' ';
        for(i=0;i<odd.size();sumodd += odd[i++])
            cout << odd[i] << ' ';
    }
    return 0;
}