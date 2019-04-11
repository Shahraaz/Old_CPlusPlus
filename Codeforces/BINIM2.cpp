#include<iostream>
#include<string>
using namespace std;
string Bstr[50];
string Game(int n,string player){
    int zero = 0,one = 0,i,j,value;
    for(i=0;i<n;i++)
        for(j=0;j<Bstr[i].length();){
            int temp = Bstr[i][j],count=1;
            while(j<Bstr[i].length()&&Bstr[i][j]==temp)
                j++;
            if(temp=='0') zero += count;
            else one += count;
        }
    if(zero==one) return (player == "Dee" ? "Dee" : "Dum");
    else return (zero > one ? "Dum" : "Dee");  
}
int main(){
    int t,n,i;
    string temp;
    cin >> t;
    while(t--){
        cin >> n >> temp;
        for(i=0;i<n;i++)
            cin >> Bstr[i];
        cout << Game(n,temp) << '\n';
    }
    return 0;
}