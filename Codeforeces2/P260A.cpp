#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main(){
    int n,i;
    cin >> n;
    vector< pair<int,int> > Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i].first >> Vect[i].second;
    sort(Vect.begin(),Vect.end());
    for(i=0;i<n-1;i++)
        if(Vect[i+1].second < Vect[i].second){
            cout << "Happy Alex";
            return 0;
        }
    cout << "Poor Alex";
    return 0;
}