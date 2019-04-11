#include<iostream>
#include<vector>
using namespace std;
vector<int> Vect(1000001,1);
void Con(){
    int count = 1,i,j;
    for(i=2;i<=100;++i){
        int temp = i*i*i; 
        for(j=temp;j<=1000000;j+=temp)
            Vect[j] = 0;
    }
    for(i=1;i<=1000000;++i)
        if(Vect[i])
            Vect[i] = count++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Con();
    int i,t,n;
    cin >> t;
    for(i=1;i<=t;i++){
        cout << "Case " << i<<": ";
        cin >> n;
        if(Vect[n]==0)
            cout << "Not Cube Free";
        else
            cout << Vect[n];
        cout << '\n';
    }
}