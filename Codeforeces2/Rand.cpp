#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n, m, i,j,ctr ;
    cin >> n >> m;
    vector<string> V(n);
    for(i=0;i<n;i++)
        cin >> V[i];
    ctr = 0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(j>0 && V[i][j]=='W' && V[i][j-1]=='P')   ctr++, V[i][j-1] = '.';
            else if(j<m-1 && V[i][j]=='W' && V[i][j+1]=='P')   ctr++, V[i][j+1] = '.';
            else if(i>0 && V[i][j]=='W' && V[i-1][j]=='P')   ctr++, V[i-1][j] = '.';
            else if(i<n-1 && V[i][j]=='W' && V[i+1][j]=='P')   ctr++, V[i+1][j] = '.';
    cout << ctr;
    return 0;
}