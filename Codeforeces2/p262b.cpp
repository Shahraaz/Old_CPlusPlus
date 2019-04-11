#include<iostream>
#include<vector>
using namespace std;
int s(long long x){
    int sum=0;
    for(;x;x/=10)
        sum += x%10;
    return sum;
}
long long pow(int base,int power){
    if(power==0) return 1;
    long long temp = pow(base,power/2);
    temp = temp*temp;
    if(power&1) return temp*base;
    return temp;
}
int main(){
    long long x,b,c,a,i,answer=0;
    cin >> a >> b >> c;
    vector<long long> Vect;
    i = 1;
    do{
        x = c + b*pow(i,a);
        if(x>0 && x<1000000000 && i==s(x)){ 
            answer++;
            Vect.push_back(x);
            // cout << x << '\n' << 1000000000 << ' '<<  (x<1000000000) << '\n'; 
        }
        i++;
    }while(i<=100);
    cout << answer << '\n';
    for(i=0;i<answer;i++)
     cout << Vect[i] << ' ';
    return 0;
}