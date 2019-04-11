#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
void ConstructSeive(ll n){
    vector<bool> Seive(10001,true);
    Seive[0] = Seive[1] = false;
    ll count,limit = ceil(sqrt(n))+1, i ,j, num ;
    cout << "2^";
    for(i=4,count=1;i<=n;i+=2){
        Seive[i]=false;
        j = i;
        while(j%2==0){
            j /= 2;
            count++;
        }
    }
    cout << count;
    for(i=3;i<=n;i+=2)
        if(Seive[i]){
            count=1;
            cout << " * " << i << "^";
            for(j=2*i;j<=n;j+=i){
                num = j;
                while(num%i==0){
                    num /= i;
                    count++;
                }
                Seive[j] = false;
            }
            cout << count;
        }
}
int main(){
    ll n;
    cin >> n;
    ConstructSeive(n);
    return 0;
}