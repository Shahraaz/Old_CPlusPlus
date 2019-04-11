#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool> Vect(1000001,true);
vector<long long int> arr(1000001,1);
void Con(){
    int count = 1,i,j;
    Vect[0] = Vect[1] = false;
    arr[0] = arr[1] = 0L;
    arr[2] = 1L;
    for(j=4;j<=1000000;j+=2){
        Vect[j] = false;
        arr[j] += 2L;
    }
    for(i=3;i<=1000000;++i)
        for(j=2*i;j<=1000000;j+=i)
            arr[j] += (long long)i;
    for(i=1;i<=1000000;i++)
        arr[i] += arr[i-1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Con();
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << arr[(long long)n];
        cout << '\n';
    }
}