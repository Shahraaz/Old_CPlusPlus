#include<iostream>
#include<vector>
using namespace std;
vector<int> prime;
void Seive(){
    vector<bool> seive(1420000,true);
    seive[0]=seive[1]=false;
    int i;
    for(i=3;i<1200;i+=2)
        if(seive[i])
            for(int j=i*i;j<=1420000;j+=i)
                seive[j] = false;
    prime.push_back(2);
    for(i=3;i<1420000;i+=2)
        if(seive[i]) prime.push_back(i);
}
int main(){
    Seive();
    // cout << prime.size();
    int i,n;
    cin >> n;
    for(i=0;i<n;i++)
        cout << prime[i] << ' ';
    return 0;
}