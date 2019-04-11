#include<iostream>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
set<int> Primes;
void ConstructSeive(){
    vector<bool> Seive(1000001,false);
    Seive[0] = Seive[1] = false;
    Seive[2] = Seive[3] = true;
    for(i=2;i<=1000;i++)
        if(Seive[i]){
            Primes.insert(i);
            for(j=i*i;j<=1000000;j+=i)
                Seive[j] = false;
        }
}
int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}
int main(){
    ConstructSeive();
    int n,i,minprime=100000000;
    cin >> n;
    set<int> Vect;
    set<int> PrimeDevisors,comDevisors;
    cout << 1 << ' ';
    for(i=2;i<=n;i++){
        if(n%i!=0){
            cout << "1 ";
        }
        else if(Primes.count(i)){
                PrimeDevisors.insert(i);
        }
        else{
            comDevisors.insert(i);            
        }
    }
    minprime = PrimeDevisors.begin();
    for (std::set<int>::iterator it=comDevisors.begin(); it!=comDevisors.end(); ++it){
        if(*it%minprime!=0){
            cout << "1 ";
            comDevisors.erase(*it);
        }
    }
    return 0;
}