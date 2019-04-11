#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    int t,n,f,temp;
    cin >> t;
    while(t--){
        cin >> n >> f;
        long long int Ans = 0,max=-1,ctr;
        while(n--){
            cin >> temp;
            if(temp>max) max = temp;
            Ans += temp*temp;
        }
        f++;
        long double Ans1 = Ans/f,Ans2 = Ans/f;
        ctr = 2;
        cout << max;
        while(Ans2 > max*max)
            Ans2 = Ans1/ctr++;
        cout << std::setprecision(9) <<M_PI*Ans2 << '\n';
    }    
    return 0;
}