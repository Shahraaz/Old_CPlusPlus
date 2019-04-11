#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
string Fun(vector< pair<int,int> > Vect,unsigned long long int s,unsigned long long int n){
    for(int i=0;i<n;i++){
        if(Vect[i].first<s)
            s+=Vect[i].second;
        else return "NO";
    }
    return "YES";
}

int main(){
    unsigned long long int i,s,n,a,b;
    cin >> s >> n;
    vector< pair<int,int> > Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i].first >> Vect[i].second;
    sort(Vect.begin(),Vect.end());
    cout << Fun(Vect,s,n);
    return 0;
}