#include<iostream>
using namespace std;
int main(){
    int n,k,i,j;
    cin >> n >> k;
    for(i=0;i<n;i++,cout << '\n')
        for(j=0;j<n;j++)
            if(j==i) cout << k << ' ';
            else cout << 0 << ' ';
    return 0;
}