#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin >> n;
    long long sum = 0;
    vector<int> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    sort(Vect.begin(),Vect.end());
    for(i=0;i<n;i++)
        sum += abs(Vect[i]-i-1);
    cout << sum ;
    return 0;
}