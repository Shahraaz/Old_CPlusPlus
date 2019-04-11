#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t,temp,temp2;
    cin >> t;
    temp2 = t;
    vector<int> Vect;
    while(t--){
        cin >> temp;
        Vect.push_back(temp);
    }
    sort(Vect.begin(),Vect.end());
    for(t=0;t<temp2;t++)
        cout << Vect[t] << '\n';
    return 0;
}