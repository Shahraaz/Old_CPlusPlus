#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> Vect = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};   
    int i,input,length = Vect.size();
    cin >> input;
    for(i=0;i<length;i++)
        if(input%Vect[i]==0){ cout << "YES" ; return 0; }
    cout << "NO";
    return 0;
}