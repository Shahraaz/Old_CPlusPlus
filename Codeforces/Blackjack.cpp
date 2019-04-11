#include<iostream>
using namespace std;
int main(){
    int n,arr[]={0,4,4,4,4,4,4,4,4,4,15,4};
    cin >> n;
    if(n<=10) cout << 0;
    else if(n>21) cout << 0;
    else cout << arr[n-10];
    return 0;
}