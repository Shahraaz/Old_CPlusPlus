#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m,i;
    cin >> n >> m;
    vector<int> Vect(m);
    i=m;
    while(i--)
        cin >> Vect[i];
    sort(Vect.begin(),Vect.end());
    int min = Vect[n-1]-Vect[0];
    for(i=1;i<=m-n;i++)
        if((Vect[n-1+i]-Vect[i]) < min) min = (Vect[n-1+i]-Vect[i]);
    cout << min;
    return 0;
}