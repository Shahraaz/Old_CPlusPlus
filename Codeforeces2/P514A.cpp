#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n,l,a,i,temp1,temp2;
    cin >> n >> l >> a;
    vector< pair<int,int> > Vect(n);
    for(i=0;i<n;i++){
        cin >> temp1 >> temp2;
        Vect[i].first = temp1;
        Vect[i].second = temp2;
    }
    sort(Vect.begin(),Vect.end());
    long long int breaks = 0,time=0;
    for(i=0;i<n;i++){
        while(time+a<=Vect[i].first){
            time += a;
            breaks++;
        }
        time = Vect[i].first;
        time += Vect[i].second;
        if(time>l) break;
    }
    while(time+a<=l){
        time += a;
        breaks++;
    }
    cout << breaks;
    return 0;
}