#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> Mat(101);
int m,n,i,j;
int main(){
    cin >> n >> m;
    for(i=0;i<n;i++)
        cin >> Mat[i];
    for(i=0;i<n;i++,cout << '\n')
        for(j=0;j<m;j++)
            if(Mat[i][j]=='.'){
                if((i+j)&1) cout << 'W';
                else cout << 'B'; 
            }
            else cout << '-';
    return 0;
}