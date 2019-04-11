#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n, k, x, min_= 1;
    cin >> n >> k;
    long long sum = 0;
    for(i=0;i<n;i++){
        cin >> x;
        if(k){
            if(x<0){
                sum += abs(x);
                min_ = x;
                k--;
            }
            else{
                if(k%2==1){
                    if(min_<0)
                        sum += max(abs(x),abs(min_)) - min(abs(x),abs(min_));
                    else sum -= x;
                }
                else
                    sum += x;
                k = 0;
            }
        }
        else
            sum += x;
    }
    cout << sum;
    return 0;
}