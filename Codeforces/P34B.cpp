#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int i,n , m,temp,sum=0 ;
    cin >> n >> m;
    vector<int> Vect(n);
    for(i=0;i<n;i++)
        cin >> Vect[i];
    sort(Vect.begin(),Vect.end());
    for(i=0;i<n;i++){
        if(m && Vect[i]<0){
            sum -= Vect[i];
            m--;
        }
        else break;
    }
    cout << sum;
    return 0;
}