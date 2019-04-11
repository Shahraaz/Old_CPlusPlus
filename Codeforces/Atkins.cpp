#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
vector<int> Primes;
void ConstructSeive(){
    vector<bool> Seive(1000001,false);
    Seive[0] = Seive[1] = false;
    Seive[2] = Seive[3] = true;
    ll limit = 1000, i ,j, num, n= 1000000 ;
    for(i=1;i<=limit;i++)
        for(j=1;j<=limit;j++){
            num  = 4*i*i + j*j;
            if(num<=n & (num%12==1 | num%12==5))
                Seive[num] = true;
            num  = 3*i*i + j*j;
            if(num<=n & num%12==7)
                Seive[num] = true;
            if(i>j){
                num = 3*i*i - j*j;
                if(num<=n & num%12==11)
                    Seive[num] = true;    
            }
        }
    for(i=5;i<=limit;i++)
        if(Seive[i])
            for(j=i*i;j<=n;j+=i)
                Seive[j] = false;
    Primes.push_back(2);
    for(i=3;i<=n;i+=2)
        if(Seive[i])
            Primes.push_back(i);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ConstructSeive();
    ll t,n,i;
    short int arr[100001] ;
    /*cin >> t;
    while(t--){
        cin >> n  ;
        for(i=0;i<n;i++)
            cin >> arr[i];
        
        cout << '\n' ;
    }*/
    for(i=0;i<20;i++)
        cout << Primes[i] << ' ';
	return 0;
}
