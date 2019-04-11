#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n,m,i,j;
    cin >> n >> m;
    vector<string> Vect(n);
    vector<string> Vect2(n);
    string temp;
    for(i=0;i<n;i++){
        cin >> temp;
        Vect[i] = temp;
        Vect2[i] = temp;
    }
    for(j=1;j<n-1;j++){
        for(i=1;i<m-1;i++){
                if(Vect[j-1][i-1]=='#' && Vect[j-1][i]=='#' && Vect[j-1][i+1]=='#' && Vect[j][i-1]=='#' && Vect[j][i+1]=='#' && Vect[j+1][i-1]=='#' && Vect[j+1][i]=='#' && Vect[j+1][i+1]=='#' ){
                    Vect2[j-1][i-1]='.';Vect2[j-1][i]='.'; Vect2[j-1][i+1]='.';
                    Vect2[j+1][i]='.'; Vect2[j+1][i+1]='.'; Vect2[j+1][i-1]='.'; 
                    Vect2[j][i+1]='.'; Vect2[j][i-1]='.';
                }
        }
    }
    for(j=0;j<n;j++)
        for(i=0;i<m;i++)
            if(Vect2[j][i]!='.'){
                cout << "NO";
                return 0;
            }
    cout << "YES";
    return 0;
}