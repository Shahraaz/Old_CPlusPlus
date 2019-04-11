#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m,k,i;
    cin >> n >> m >> k;
    vector<int> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    long long sum=0;
    vector<long long> Sumi;
    for(i=0;i<m;i++)
        sum += Vect[i];
    Sumi.push_back(sum);
    for(i=1;i<=n-m;i++){
        sum += Vect[i+m-1] - Vect[i-1];
        Sumi.push_back(sum);
    }
    sort(Sumi.begin(),Sumi.end());
    for(i=sum=0;i<k;i++)
        sum += Sumi[Sumi.size()-1-i];
    cout << sum ;
    return 0;
}