#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;
int main(){
    int n,i,perfect=0;
    cin >> n;
    vector<int> Vect(n),missed;
    for(i=0;i<n;i++){
           cin >> Vect[i];
           if(Vect[i]!=i)
               missed.push_back(i);
           else perfect++;
    }
    if(missed.size()==0) cout << perfect;
    else{
        for(i=0;i<missed.size();i++)
            if(Vect[Vect[missed[i]]]==missed[i]){
                cout << perfect + 2;
                return 0;
            }
        cout << perfect + 1;
    }
    return 0;
}