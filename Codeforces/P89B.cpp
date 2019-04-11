#include<iostream>
using namespace std;
int main(){
    int n,i,j,k;
    cin >> n;
    for(i=0;i<=n;i++){
        if(i==n){
            for(k=0;k<=i;k++)
            cout << k << ' ' ;
            for(k=i-1;k>=0;k--)
                if(k==0) cout << k;
                else
                    cout << k << ' ';
            cout << '\n';
            break;
        }
        for(j=0;j<2*(n-i)-1;j++)
            cout << " ";
        for(k=0;k<=i;k++)
            cout << ' ' << k ;
        for(k=i-1;k>=0;k--)
            cout << ' ' << k;
        cout << '\n';
    }
    for(i=n-1;i>=0;i--){
        for(j=0;j<2*(n-i)-1;j++)
            cout << " ";
        for(k=0;k<=i;k++)
            cout << ' ' << k ;
        for(k=i-1;k>=0;k--)
            cout << ' ' << k;
        cout << '\n';
    }
    return 0;
}