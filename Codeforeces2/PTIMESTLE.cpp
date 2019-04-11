#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
vector<int> Primes;
void ConstructSeive(){
    vector<bool> Seive(10001,true);
    Seive[0] = Seive[1] = false;
    ll limit = 100, i ,j, num, n= 10000 ;
    Primes.push_back(2);
    for(i=3;i<=limit;i+=2)
        if(Seive[i])
            for(j=i*i,Primes.push_back(i);j<=n;j+=i)
                Seive[j] = false;
    for(i=101;i<=n;i+=2)
        if(Seive[i])
            Primes.push_back(i);
}
int main(){
    ConstructSeive();
    int i,n,j,length = Primes.size();
    cin >> n;
    bool nedula = false;
    vector<int> Vect(1001);
    for(i=0;i<=1000;i++)
        Vect[i] = i;
    for(i=0;i<length;i++){
        int power = 0;    
        for(j=2;j<=n;j++){
            if(j%Primes[i]==0){
                while(Vect[j]%Primes[i]==0){
                    power++;
                    Vect[j] /= Primes[i];
                }
            }
        }
        if(power>0){
            if(nedula) cout << " * ";
            cout << Primes[i] << '^' << power ;
            nedula = true;
        }
    }
    return 0;
} 