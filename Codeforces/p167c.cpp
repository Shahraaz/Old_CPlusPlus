#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,h,w;
    cin >> n;
    vector<long long int> Vect(n);
    for(i=0;i<n;++i)
        cin >> Vect[i];
    cin >> m;
    for(i=0;i<m;++i){
        cin >> w >> h;
        Vect[0] = max(Vect[0],Vect[w-1]);
        cout << Vect[0] << '\n';
        Vect[0] += h;
    }
    return 0;
}