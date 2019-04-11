#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,s,t,i;
    cin >> n >> s >> t;
    vector<int> Vect(n+1);
    for(i=1;i<=n;i++)
        cin >> Vect[i];
    for(i=0;i<n;i++){
        if(s==t){
            cout << i;
            return 0;
        }
        s = Vect[s];
    }
    if(s==t)
        cout << i;
    else cout << -1;
    return 0;
}