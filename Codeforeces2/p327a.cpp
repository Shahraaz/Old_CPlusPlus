#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i,x,j,max=0,sum=0;
    cin >> n;
    vector<int> Vect(n+2,0),n1(n+2,0),n0(n+2,0);
    for(i=1;i<=n;i++){
        cin >> Vect[i];
        sum += Vect[i];
        n1[i] = n1[i-1] + (Vect[i]==1);
        n0[i] = n0[i-1] + (Vect[i]==0);
    }
    n1[n+1] = n1[n] ;
    n0[n+1] = n0[n] ;
    // for(i=1;i<=n+1;i++) cout << n0[i] << ' '; cout << '\n';
    // for(i=1;i<=n+1;i++) cout << n1[i] << ' '; cout << '\n';
    max = sum - n1[1] + n0[1];
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            if(sum-n1[j]+n1[i-1]+n0[j]-n0[i-1] > max) 
                max = sum -n1[j]+n1[i-1]+n0[j]-n0[i-1];
    cout << max;
    return 0;
}