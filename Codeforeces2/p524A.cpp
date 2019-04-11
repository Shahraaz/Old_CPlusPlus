#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    cout << (8*n)/k + ((8*n%k!=0))
            +(5*n)/k + ((5*n%k!=0))+
            (2*n)/k + ((2*n%k!=0)) ;
    return 0;
}