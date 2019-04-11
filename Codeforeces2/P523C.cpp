#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> prime;
void Seive(){
    int i,j;
    vector<bool> Seive(1000006,true);
    Seive[0]=Seive[1]=false;
    for(i=4;i<=1000000;i+=2)
        Seive[i] = false;
    for(i=3;i<=1000;i+=3)
        if(Seive[i])
            for(j=i*i;j<=1000000;j+=i)
                Seive[j] = false;
    prime.push_back(2);
    for(i=3;i<=1000000;i+=2)
        if(Seive[i])    prime.push_back(i);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x,j;
    cin >> n;
    // Seive();
    vector<long long> Dp(1000005,0);
    Dp[0]=1;
    for(i=0;i<n;i++){
        cin >> x;
        vector<int> factors;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                factors.push_back(i);
                if(x/i!=i)
                    factors.push_back(x/i);
            }
        }
        sort(factors.begin(),factors.end());
        // cout << "factors " << x << '\n';
        for(j=factors.size()-1;j>=0;j--){
            Dp[factors[j]] += Dp[factors[j]-1];
            Dp[factors[j]] %= (1000000007);
            // cout << factors[j] << ' ' << Dp[factors[j]] << '\n';
        } 
        // cout << '\n';
    }
    long long answer = 0;
    for(i=1;i<=1000000;i++){
        answer += Dp[i];
        answer = answer % (1000000007);
    }
    cout << answer;
    return 0;
}