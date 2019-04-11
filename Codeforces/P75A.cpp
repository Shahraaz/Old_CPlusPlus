#include<iostream>
using namespace std;
int Fun(int n,int m){
    if(m==0) return 0;
    int i;
    for(i=1;i<=n;i++){
        if(m>=i)
            m-=i;
        else return m;
    }
    return Fun(n,m);
}
int main(){
    int n,m;
    cin >> n >> m;
    cout << Fun(n,m);
    return 0;
}