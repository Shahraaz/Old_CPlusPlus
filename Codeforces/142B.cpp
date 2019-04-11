#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
vector<bool> Seive(1000001,true);
void ConstructSeive(){
    Seive[0] = Seive[1] = false;
    Seive[2] = Seive[3] = true;
    ll limit = 1000, i ,j, n= 1000000 ;
    for(i=2;i<=limit;i++)
        if(Seive[i]){
            for(j=i*i;j<=n;j+=i)
                Seive[j] = false;
        }
}
bool isSquare(unsigned long long int n){
    if(sqrt(n) == floor(sqrt(n))) return true;
    return false;
}
int main(){
    ConstructSeive();
    int n;
    unsigned long long int temp;
    cin >> n;
    while(n--){
        cin >> temp;
        if(isSquare(temp))
            if(Seive[(int)sqrt(temp)])    cout << "YES\n";
            else cout << "NO\n";
        else cout << "NO\n";
    }
    return 0;
}