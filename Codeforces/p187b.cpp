#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q,x,v,i;
    cin >> n >> m;
    vector<long long> Vect(n+1),INC(n+1,0);
    long long int inc = 0;
    for(i=1;i<=n;i++)
        cin >> Vect[i];
    while(m--){
        cin >> q;
        if(q==1){
            cin >> v >> x;
            Vect[v] = x;
            INC[v] = - inc;
        }
        else if(q==2){
            cin >> x;
            inc += x;
        }
        else{
            cin >> v;
            cout << inc + Vect[v] + INC[v] << '\n';
        }
    }
    return 0;
}