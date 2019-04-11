#include<iostream>
using namespace std;
int main(){
    int i,n,j,counter=0;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=1;j<=n;j++){
            if(counter+j>n) cout << (j-1)*n+counter+j-n << ' ';
            else cout << (j-1)*n+counter + j << ' ';
        }
        cout << endl;
        counter ++;
    }
    return 0;
}